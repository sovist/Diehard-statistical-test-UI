#include "..//code_files/include/libdieharder.h"

  unsigned int all;              /* Flag to do all tests on selected generator */
  unsigned int binary;           /* Flag to output rands in binary (with -o -f) */
  unsigned int bits;             /* bitstring size (in bits) */
  unsigned int diehard;          /* Diehard test number */
  unsigned int generator;        /* GSL generator id number to be tested */

  char gnames[GVECMAX][128];     /* VECTOR of names to be XOR'd into a "super" generator */
  unsigned int gseeds[GVECMAX];  /* VECTOR of unsigned int seeds used for the "super" generators */
  unsigned int gnumbs[GVECMAX];  /* VECTOR of GSL generators to be XOR'd into a "super" generator */
  unsigned int gvcount;          /* Number of generators to be XOR'd into a "super" generator */
  unsigned int gscount;          /* Number of seeds entered on the CL in XOR mode */
  unsigned int help_flag;        /* Help flag */
  unsigned int hist_flag;        /* Histogram display flag */
           int iterations;	    /* For timing loop, set iterations to be timed */
  unsigned int ks_test;          /* Selects the KS test to be used, 0 = Kuiper 1 = Anderson-Darling */
  unsigned int list;             /* List all tests flag */
  unsigned int List;             /* List all generators flag */
  double multiply_p;	            /* multiplier for default # of psamples in -a(ll) */
  unsigned int ntuple;           /* n-tuple size for n-tuple tests */
  unsigned int num_randoms;      /* the number of randoms stored into memory and usable */
  unsigned int output_file;      /* equals 1 if you output to file, otherwise 0. */
  unsigned int output_format;    /* equals 0 (binary), 1 (unsigned int), 2 (decimal) output */
  unsigned int overlap;          /* 1 use overlapping samples, 0 don't (for tests with the option) */
  unsigned int psamples;         /* Number of test runs in final KS test */
  unsigned int quiet;            /* quiet flag -- surpresses full output report */
  unsigned int rgb;              /* rgb test number */
  unsigned int sts;              /* sts test number */
  unsigned int Seed;             /* user selected seed.  Surpresses reseeding per sample.*/
  off_t tsamples;                /* Generally should be "a lot".  off_t is u_int64_t. */
  unsigned int user;             /* user defined test number */
  unsigned int verbose;          /* Default is not to be verbose. */
  double Xweak;                  /* "Weak" generator cut-off (one sided) */
  double Xfail;                  /* "Unambiguous Fail" generator cut-off (one sided) */
  unsigned int Xtrategy;         /* Strategy used in TTD mode */
  unsigned int Xstep;            /* Number of additional psamples in TTD/RA mode */
  unsigned int Xoff;             /* Max number of psamples in TTD/RA mode */
  double x_user;         /* Reserved general purpose command line inputs for */
  double y_user;         /* use in any new user test. */
  double z_user;
  
  double *ks_pvalue,*ks_pvalue2;
  unsigned int kspi;
  struct timeval tv_start, tv_stop;
  int dummy,idiot;
  FILE *fp;
  char **fields;

  char filename[K];      /* Input file name */
  int fromfile;		/* set true if file is used for rands */
  int filenumbits;	/* number of bits per integer */

  long long filecount;	/* number of rands in file */
  char filetype;         /* file type */

  const gsl_rng_type **types;       /* where all the rng types go */
 //gsl_rng *rng;               /* global gsl random number generator */

  gsl_matrix *A,*V;
  gsl_vector *S,*svdwork;

 unsigned long int seed;             /* rng seed of run (?) */
 unsigned int random_max;       /* maximum rng returned by generator */
 unsigned int rmax;             /* scratch space for random_max manipulation */
 unsigned int rmax_bits;        /* Number of valid bits in rng */
 unsigned int rmax_mask;        /* Mask for valid section of unsigned int */

 double progressGeneralInc;
 double progressGeneral;
 double progressTest;
 int fileRewound;
 FILE* inputFile;
 
