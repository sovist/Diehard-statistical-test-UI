/*
* $Id: timing.c 223 2006-08-17 06:19:38Z rgb $
*
* See copyright in copyright.h and the accompanying file COPYING
*
*/

/*
 *========================================================================
 * timing and utility sources.  tv_start and tv_stop are globals.
 *========================================================================
 */

#include "../code_files/include/libdieharder.h"
#include "../code_files/include/time_.h"


void start_timing()
{
 gettimeofDay(&tv_start, /*(struct timezone*)*/ NULL);
}

void stop_timing()
{
 gettimeofDay(&tv_stop, /*(struct timezone *)*/ NULL);
}

double delta_timing()
{
 return((double)(tv_stop.tv_sec - tv_start.tv_sec) + 1.0e-6*(double)(tv_stop.tv_usec - tv_start.tv_usec));
}

unsigned int makeseed() 
{
 struct timeval tv;
 gettimeofDay(&tv,0);
 return tv.tv_sec + tv.tv_usec;
}

