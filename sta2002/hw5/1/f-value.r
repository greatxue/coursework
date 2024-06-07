alpha <- 0.05
df1 <- 2
df2 <- 12

f_critical <- qf(1 - alpha, df1, df2)

print(f_critical)