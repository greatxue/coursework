setwd("~/Github/cs_assignments/cuhksz_STA2002/hw1")

smiles <- read.table("smiles.txt")
names(smiles) <- c("groups", "scores")
attach(smiles)


## Part 1:

# Histograms
splitgroup <- split(scores, groups)
attach(splitgroup)
par(mfrow = c(2, 2))
hist(false, main = "")
hist(felt, main = "")
hist(miserable, main = "")
hist(neutral, main = "")

# Stem-and-leaf plots
tapply(scores, groups, stem)

## Part 2:

# 5-number summaries
summary(false)
var(false)
sd(false)

summary(felt)
var(felt)
sd(felt)

summary(miserable)
var(miserable)
sd(miserable)

summary(neutral)
var(neutral)
sd(neutral)

# Boxplots
par(mfrow = c(2, 2))
boxplot(false)
title("false")
boxplot(felt)
title("felt")
boxplot(miserable)
title("miserable")
boxplot(neutral)
title("neutral")

