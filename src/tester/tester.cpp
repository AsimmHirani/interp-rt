//
// Created by Asimm on 2021-09-06.
//

#include "interp-rt.h"
#include "test.h"

#include <vector>
#include <fstream>

INTERP_RT_lut_t lut = {
        .x = interp_rt_x,
        .c = reinterpret_cast<INTERP_RT_coeff_dt *>(interp_rt_c),
        .len = LUT_X_CT,
        .pow = 3
};

char const * filename = "test-result.csv";

float start = 0.0f;
float end = 10.0f;

float dt = 0.000001f;

int main() {
    std::ofstream outfile(filename);
    outfile << "x,y" << std::endl;
    // make the vectors
    float x = start;
    while (x < end) {
        outfile << x << ',' << INTERP_RT_interpolate1d(&lut, x) << '\n';
        x += dt;
    }

    outfile.close();
    return 0;
}