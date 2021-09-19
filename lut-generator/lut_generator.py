from InterpRTGenerator import InterpRTGenerator as interp
import pandas as pd
import numpy as np
import scipy.interpolate as sci_interp
import matplotlib.pyplot as plt


def main():
    df = pd.DataFrame()
    df['x'] = np.linspace(0,10,15)
    df['y'] = -(df['x']-5)**2+25
    print(df)
    i = interp(df,True)
    i.write_out('test')
    plt.plot(df['x'],df['y'])
    plt.show()

if (__name__ == '__main__'):
    main()