#ifndef _STATIC_GET_BITS_H_
#define _STATIC_GET_BITS_H_

#include "dieharder_rng_types.h"

unsigned int get_rand_bits_uint (unsigned int nbits, unsigned int mask, gsl_rng *rng);
unsigned int get_bit_ntuple_from_uint (unsigned int bitstr, unsigned int nbits, unsigned int mask, unsigned int boffset);
unsigned int get_bit_ntuple_from_whole_uint (unsigned int bitstr, unsigned int nbits, unsigned int mask, unsigned int boffset);

#endif // !_STATIC_GET_BITS_H_