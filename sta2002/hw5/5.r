x1 <- c(25, 31, 45, 60, 65, 72, 80, 84, 75, 60, 50, 38)
x2 <- c(24, 21, 24, 25, 25, 26, 25, 25, 24, 25, 25, 23)
x3 <- c(91, 90, 88, 87, 91, 94, 87, 86, 88, 91, 90, 89)
x4 <- c(100, 95, 110, 88, 94, 99, 97, 96, 110, 105, 100, 98)

y <- c(240, 236, 270, 274, 301, 316, 300, 296, 267, 276, 288, 261)

model <- lm(y ~ x1 + x2 + x3 + x4)
summary(model)