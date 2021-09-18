import pandas as pd
import numpy as np
import scipy.interpolate as sci_interp

class InterpRTGenerator:
    def __init__(self,df:pd.DataFrame,floating_point:bool) -> None:
        self.floating_point = floating_point
        self.x = df['x']
        self.y = df['y']
        cb = sci_interp.CubicSpline(df['x'],df['y'])
        self.c = np.array(cb.c)
    def write_out(self,outfile:str):
        f = open(outfile+'.h','w')
        f.write('#ifndef _'+outfile.upper()+'_H_\n#define _'+outfile.upper()+'_H_\n')
        f.write('#define LUT_X_CT ('+str(self.x.size)+')\n')
        f.write('#define LUT_C_ROWS_CT ('+str(self.c.shape[0])+')\n')
        f.write('#define LUT_C_COLS_CT ('+str(self.c.shape[1])+')\n\n')
        f.write('extern float interp_rt_x[LUT_X_CT];\n')
        f.write('extern float interp_rt_c[LUT_C_ROWS_CT][LUT_C_COLS_CT];\n\n')
        f.write('#endif // _'+outfile.upper()+'_H_\n')
        f.close()
        f = open(outfile+'.c','w')
        f.write('#include "'+outfile+'.h"\n\n')
        f.write('float interp_rt_x[] = {\n\t')
        f.write(self.x.to_csv(index=False,header=False,line_terminator='f,\n\t')[0:-3])
        f.write('\n};\n')
        f.write('float interp_rt_c[LUT_C_ROWS_CT][LUT_C_COLS_CT] = {\n\t')
        f.write(pd.Series(self.c.flatten(order='F')).to_csv(index=False,header=False,line_terminator='f,\n\t')[0:-3])
        f.write('\n};\n')
        f.close()
        