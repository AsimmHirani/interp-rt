#include "interp-rt.h"

#include <libfixmath/fix16.h>
#include <libfixmath/fract32.h>


static unsigned int monobound_binary_search(INTERP_RT_dt const * array, unsigned int array_size, INTERP_RT_dt key);

INTERP_RT_dt INTERP_RT_interpolate1d(INTERP_RT_lut_t const * lut, INTERP_RT_dt x0) {
    unsigned int nn1_idx;
    INTERP_RT_dt range,diff;
    fract32_t fract;

    if (x0 < lut->x[0] || x0 > lut->x[lut->len-1]) {
        if (INTERP_RT_EXTRAPOLATE == 0)
            return INTERP_RT_ERR;
        // TODO: Implement Extrapolation
    }
    nn1_idx = monobound_binary_search(lut->x,lut->len,x0);
    range = fix16_sub(lut->x[nn1_idx],lut->x[nn1_idx-1]);
    diff = fix16_sub(x0,lut->x[nn1_idx-1]);
    fract = fract32_create(diff,range);

    return fix16_lerp32(lut->y[nn1_idx],lut->y[nn1_idx-1],fract);
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

