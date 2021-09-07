import pandas as pd
import matplotlib.pyplot as plt

def main():
    df = pd.read_csv('test-result.csv')
    df.plot(x='x',y='y')
    plt.show()

if (__name__ == '__main__'):
    main()