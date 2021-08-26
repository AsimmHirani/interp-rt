#ifndef INTERP_RT_INTERP_RT_H
#define INTERP_RT_INTERP_RT_H

#include <libfixmath/fix16.h>

// If 1, we will extrapolate outside dataset
#define INTERP_RT_EXTRAPOLATE (0)
#define INTERP_RT_FRAC_BIT ((unsigned int) 16)
#define INTERP_RT_ERR   (-1)

typedef fix16_t INTERP_RT_dt; /* Default Datatype */

/* Lookup table definition */
typedef struct INTERP_RT_lut {
    INTERP_RT_dt* x; // must be sorted, x indices
    INTERP_RT_dt* y; // must be sorted, y indices
    unsigned int len; // number of elements
} INTERP_RT_lut_t;

INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0);

#endif //INTERP_RT_INTERP_RT_H
