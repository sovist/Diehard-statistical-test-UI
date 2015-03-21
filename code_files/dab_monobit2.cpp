/*
 * ========================================================================
 * $Id: sts_monobit.c 237 2006-08-23 01:33:46Z rgb $
 *
 * See copyright in copyright.h and the accompanying file COPYING
 * See also accompanying file STS.COPYING
 * ========================================================================
 */

/*
 * ========================================================================
 * Block-monobit test.
 * Since we don't know what block size to use, try a bunch of block sizes.
 * In particular, try all blocks sizes of 2^k words, where k={0..n}.
 * Not sure what n should be. Especially considering the difficulty with
 * getting a statistic out of the test.
 * ========================================================================
 */

#include "../code_files/include/libdieharder.h"


#define BLOCK_MAX (16)

/* The evalMostExtreme function is in dab_dct.c */
extern double evalMostExtreme(double *pvalue, unsigned int num);

int dab_monobit2(Test **test, int irun)
{
 unsigned int i, j;
 unsigned int blens = rmax_bits;
 unsigned int ntup = ntuple;
 double *counts;
 unsigned int *tempCount;
 double pvalues[BLOCK_MAX];

 /* First, find out the maximum block size to use.
  * The maximum size will be 2^ntup words.
  */
 if (ntup == 0) {
   for (j=0;j<BLOCK_MAX;j++) {
     unsigned int nmax = blens * (2<<j);
     unsigned int nsamp = test[0]->tsamples / (2<<j);
     if ( nsamp*gsl_ran_binomial_pdf(nmax/2,0.5,nmax) < 20 ) break;
   }
   ntup = j;
 }

 test[0]->ntuple = ntup;

 counts = (double *) malloc(sizeof(*counts) * blens * (2<<ntup));  // 1 << (ntup+1)
 memset(counts, 0, sizeof(*counts) * blens * (2<<ntup));

 tempCount = (unsigned int *) malloc(sizeof(*tempCount) * ntup);
 memset(tempCount, 0, sizeof(*tempCount) * ntup);

 for(i=0;i<test[0]->tsamples;i++) {
   unsigned int n = gsl_rng_get(rng);
   unsigned int t = 1;

   // Begin: count bits
   n -= (n >> 1) & 0x55555555;
   n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
   n = (n + (n >> 4)) & 0x0f0f0f0f;

   if (0) {
     n = (n * 0x01010101) >> 24;
  } else {
     n = n + (n >> 8);
     n = (n + (n >> 16)) & 0x3f;
  }
  // End: count bits

  for (j = 0; j < ntup; j++) {
    tempCount[j] += n;  // Update block count

    if ((t & i) && !(t & (i-1))) {  // If this is the start of a new block
      counts[blens * ((2<<j)-1) + tempCount[j]]++;  // Save the count
      tempCount[j] = 0;  // Reset the counter
    }
    t <<=1;
  }
 }

 /* Calculate the p-value for each block size. */
 for (j = 0; j < ntup; j++) {
   double p = chisq_binomial(counts + (blens * ((2<<j)-1)), 0.5, blens * (2<<j),
       test[0]->tsamples / (2<<j));
   pvalues[j] = p;
 }

 /* Take only the most extreme p-value, and correct its value to
  * account for the number of p-values considered.
  */
 test[0]->pvalues[irun] = evalMostExtreme(pvalues, ntup);

 nullfree(counts);
 nullfree(tempCount);

 return(0);
}

