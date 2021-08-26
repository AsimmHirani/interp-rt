#include "interp-rt.h"



unsigned int monobound_binary_search(INTERP_RT_dt const * array, unsigned int array_size, INTERP_RT_dt key);
inline INTERP_RT_dt lerp(INTERP_RT_dt a, INTERP_RT_dt b, INTERP_RT_dt f);

INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0) {
    unsigned int nn1_idx;

    if (x0 < lut->x[0] || x0 > lut->x[lut->len-1]) {
        if (INTERP_RT_EXTRAPOLATE == 0)
            return INTERP_RT_ERR;
        // TODO: Implement Extrapolation
    }
    nn1_idx = monobound_binary_search(lut->x,lut->len,x0);

    // TODO: Linearly interpolate between nearest neighbors
}

// faster than the boundless binary search, more checks (From scandum's binary_search project, modified for nn algo)

unsigned int monobound_binary_search(INTERP_RT_dt const * const array, unsigned int array_size, INTERP_RT_dt key)
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

inline INTERP_RT_dt lerp(INTERP_RT_dt a, INTERP_RT_dt b, INTERP_RT_dt f) {
    unsigned long r1;
    unsigned int r2;

    r1 = (unsigned long)f * (b-a);
    r2 = (r1 >> INTERP_RT_FRAC_BIT) + a;

    return r2;
}
