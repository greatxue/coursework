from read_file import read_csv


# Calculate sample mean
def mean(data):
    return sum(data) / len(data)


# Calculate sample variance
def variance(data):
    m = mean(data)
    return sum((xi - m) ** 2 for xi in data) / (len(data) - 1)  
    # Remind that we use sample variance here


D = read_csv('../D.csv')
D_x_mean = mean(D[0])
D_x_variance = variance(D[0])
D_y_mean = mean(D[1])
D_y_variance = variance(D[1])

S = read_csv('../S.csv')
S_x_mean = mean(S[0])
S_x_variance = variance(S[0])
S_y_mean = mean(S[1])
S_y_variance = variance(S[1])

# Print out the results
print(f"D Dataset: x_mean = {D_x_mean:.2f}, x_variance = {D_x_variance:.2f}, y_mean = {D_y_mean:.2f}, y_variance = {D_y_variance:.2f}")
print(f"S Dataset: x_mean = {S_x_mean:.2f}, x_variance = {S_x_variance:.2f}, y_mean = {S_y_mean:.2f}, y_variance = {S_y_variance:.2f}")




