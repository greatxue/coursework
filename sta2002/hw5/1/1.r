# Brand of Pen
brand_of_pen_A <- factor(rep(c("1", "2", "3", "4"), each = 6))
# Writing Surface
writing_surface_B <- factor(rep(c("1", "2", "3"), each = 8))
values <- c(709, 659,  713, 726,  660, 645,
            668, 685,  722, 740,  692, 720,
            659, 685,  666, 684,  678, 750,
            698, 650,  704, 666,  686, 733)
df <- data.frame(brand_of_pen_A, writing_surface_B, values)
result_1 <- aov(values ~ brand_of_pen_A * writing_surface_B, data = df)
result_2 <- aov(values ~ brand_of_pen_A:writing_surface_B, data = df)
# Show ANOVA diagrams
summary(result_1)
summary(result_2)
