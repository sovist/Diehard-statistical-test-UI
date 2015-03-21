/*
 * $Id: diehard_craps.c 191 2006-07-13 08:23:50Z rgb $
 *
 * See copyright in copyright.h and the accompanying file COPYING
 *
 */

/*
 *========================================================================
 *========================================================================
 */

#include "../code_files/include/libdieharder.h"


static Dtest marsaglia_tsang_gorilla_data = 
{
	"Marsaglia and Tsang Gorilla Test",
	"\n\
	#==================================================================\n\
	#               Marsaglia and Tsang Gorilla Test\n\
	#\n\
	# THIS TEST IS UNDER CONSTRUCTION!  It does not work yet, and what\n\
	# is presented is, in fact, the output of the test template.\n\
	# Note that the second revision number will bump by one when this\n\
	# test is completed -- check back later!\n\
	#==================================================================\n",
	(char*)100,
	100000
};
static Dtest *dtest = &marsaglia_tsang_gorilla_data;


void marsaglia_tsang_gorilla(Test **test, int irun)
{

 unsigned int t,i,lag;
 Xtest ptest;

 /*
  * ptest.x = actual sum of test[0]->tsamples lagged samples from rng
  * ptest.y = test[0]->tsamples*0.5 is the expected mean value of the sum
  * ptest.sigma = sqrt(test[0]->tsamples/12.0) is the standard deviation
  */
 ptest.x = 0.0;  /* Initial value */
 ptest.y = (double) test[0]->tsamples*0.5;
 ptest.sigma = sqrt(test[0]->tsamples/12.0);

 /*
  * sample only every lag returns from the rng, discard the rest.
  * We have to get the (float) value from the user input and set
  * a uint 
  */
 if(x_user){
   lag = x_user;
 } else {
   lag = 2; /* Why not?  Anything but 0, really... */
 }

 if(verbose == D_USER_TEMPLATE || verbose == D_ALL){
   printf("# marsaglia_tsang_gorilla(): Doing a test on lag %u\n",lag);
 }

 for(t=0;t<test[0]->tsamples;t++){

   /*
    * A VERY SIMPLE test (probably not too sensitive)
    */

   /* Throw away lag-1 per sample */
   for(i=0;i<(lag-1);i++) gsl_rng_uniform(rng);

   /* sample only every lag numbers, reset counter */
   ptest.x += gsl_rng_uniform(rng);

 }

 Xtest_eval(&ptest);
 test[0]->pvalues[irun] = ptest.pvalue;

 MYDEBUG(D_MARSAGLIA_TSANG_GORILLA) {
   printf("# marsaglia_tsang_gorilla(): test[0]->pvalues[%u] = %10.5f\n",irun,test[0]->pvalues[irun]);
 }

}

