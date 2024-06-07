# (a)
x = rnorm(100, mean=100, sd=3)
mean(x)
var(x)

# (b)
n = 100 # number of observations in one sample
S = 500 # number of simulations
X = matrix(0, nrow=S, ncol=n)
for (i in 1:S){
    X[i,] = rnorm(n, mean=100, sd=3)
}
means = apply(X, 1, mean)

# (c)
hist(means)
