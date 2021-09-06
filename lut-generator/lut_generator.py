from InterpRTGenerator import InterpRTGenerator as interp
import pandas as pd
import numpy as np
import scipy.interpolate as sci_interp


def main():
    df = pd.DataFrame()
    df['x'] = np.arange(2*np.pi,step=np.pi/10)
    df['y'] = np.sin(df['x'])
    i = interp(df,True)
    i.write_out('test')

if (__name__ == '__main__'):
    main()