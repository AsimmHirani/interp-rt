#ifndef INTERP_RT_INTERP_RT_H
#define INTERP_RT_INTERP_RT_H

// If 1, we will extrapolate outside dataset
#define INTERP_RT_EXTRAPOLATE (0)
#define INTERP_RT_FRAC_BIT ((unsigned int) 16)
#define INTERP_RT_ERR   (-1)

typedef float INTERP_RT_dt; /* Default Datatype */
typedef float INTERP_RT_coeff_dt; /* Default Datatype */

/* Lookup table definition */
typedef struct INTERP_RT_lut {
    INTERP_RT_dt* x; // must be sorted, x indices
    INTERP_RT_coeff_dt* c; // Coefficients for interpolating function
    unsigned int len; // number of elements
    // segments = len-1
    unsigned int pow; // power of interpolating function
} INTERP_RT_lut_t;

#ifdef __cplusplus
extern "C" INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0);
#else
INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0);
#endif // __cplusplus

#endif //INTERP_RT_INTERP_RT_H
