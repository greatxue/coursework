from read_file import read_csv
from mean_and_var import mean


# Calculate regression parameters
def compute_regression_parameters(x_data, y_data):
    x_mean = mean(x_data)
    y_mean = mean(y_data)

    # Compute beta (slope)
    s_xy = sum((xi - x_mean) * (yi - y_mean) for xi, yi in zip(x_data, y_data))
    s_xx = sum((xi - x_mean) ** 2 for xi in x_data)
    beta = s_xy / s_xx

    # Compute alpha (intercept)
    alpha = y_mean

    return alpha, beta


D = read_csv('../D.csv')
S = read_csv('../S.csv')

D_alpha, D_beta = compute_regression_parameters(D[0], D[1])
S_alpha, S_beta = compute_regression_parameters(S[0], S[1])

# Print out the results
print(f"D Dataset: alpha = {D_alpha:.2f}, beta = {D_beta:.2f}")
print(f"S Dataset: alpha = {S_alpha:.2f}, beta = {S_beta:.2f}")
