from math import sqrt
from read_file import read_csv
from regression import compute_regression_parameters

D = read_csv('../D.csv')
S = read_csv('../S.csv')


def compute_standard_errors(x_data, y_data, alpha, beta):
    n = len(x_data)
    x_mean = sum(x_data) / n
    y_pred = [alpha + beta * (xi - x_mean) for xi in x_data]

    # Compute standard error for beta
    s_xx = sum((xi - x_mean) ** 2 for xi in x_data)
    var = sum((yi - y_hat) ** 2 / (n-2) for yi, y_hat in zip(y_data, y_pred))
    SE_beta = sqrt(var / s_xx)

    # Compute standard error for alpha
    SE_alpha = sqrt(var / n)

    return SE_alpha, SE_beta

D_alpha, D_beta = compute_regression_parameters(D[0], D[1])
S_alpha, S_beta = compute_regression_parameters(S[0], S[1])

D_SE_alpha, D_SE_beta = compute_standard_errors(D[0], D[1], D_alpha, D_beta)
S_SE_alpha, S_SE_beta = compute_standard_errors(S[0], S[1], S_alpha, S_beta)

# Compute the 95% confidence intervals
Z = 1.96  # Z-score for 95% confidence interval
D_alpha_CI = (D_alpha - Z * D_SE_alpha, D_alpha + Z * D_SE_alpha)
D_beta_CI = (D_beta - Z * D_SE_beta, D_beta + Z * D_SE_beta)
S_alpha_CI = (S_alpha - Z * S_SE_alpha, S_alpha + Z * S_SE_alpha)
S_beta_CI = (S_beta - Z * S_SE_beta, S_beta + Z * S_SE_beta)

# Print the results
print(f"D Dataset: alpha 95% CI = {D_alpha_CI}, beta 95% CI = {D_beta_CI}")
print(f"S Dataset: alpha 95% CI = {S_alpha_CI}, beta 95% CI = {S_beta_CI}")
