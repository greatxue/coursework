from read_file import read_csv
import matplotlib.pyplot as plt

D = read_csv('../D.csv')
S = read_csv('../S.csv')


# Construct scatter plots
def plot_scatter(x_data, y_data, title):
    plt.figure(figsize=(8, 6))
    plt.scatter(x_data, y_data)
    plt.title(title)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.grid(True)
    plt.show()


plot_scatter(D[0], D[1], 'Scatter plot for D dataset')
plot_scatter(S[0], S[1], 'Scatter plot for S dataset')




