#include "interp-rt.h"
#include "math.h"

static unsigned int monobound_binary_search(INTERP_RT_dt const * array, unsigned int array_size, INTERP_RT_dt key);

static inline float spl_eval(float* coeff, int nCoeffs, float x) {
    float rval = 0;
    for (int i = 0; i < nCoeffs; i++) {
        rval += coeff[i]*powf(x,nCoeffs-i-1);
    }
    return rval;
}

INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0) {
    unsigned int nn1_idx;
    INTERP_RT_dt diff;
    INTERP_RT_coeff_dt* coeffs;
    // If the input position is out of bounds, return err
    if (x0 < lut->x[0] || x0 > lut->x[lut->len-1]) {
        if (INTERP_RT_EXTRAPOLATE == 0)
            return INTERP_RT_ERR;
        // TODO: Implement Extrapolation
    }
    nn1_idx = monobound_binary_search(lut->x,lut->len,x0); // this is the lower side of the interval
    diff = x0-lut->x[nn1_idx];
    // retrieve spline coefficients from memory (move over nn1_idx rows of lut->pow+1 cols. Data width sizeof(...)
    coeffs = (lut->c+nn1_idx*(lut->pow+1));


    return spl_eval(coeffs,lut->pow+1,diff);
}

// faster than the boundless binary search, more checks (From scandum's binary_search project, modified for nn algo)

static unsigned int monobound_binary_search(INTERP_RT_dt const * const array, unsigned int array_size, INTERP_RT_dt key)
{
    unsigned int bot, mid, top;
    // Check for empty array
    if (array_size == 0) {
        return -1;
    }
    bot = 0;
    top = array_size;

    while (top > 1) {
        mid = top / 2;
        if (key >= array[bot + mid]) {
            bot += mid;
        }
        top -= mid;
    }
    return bot;
}

