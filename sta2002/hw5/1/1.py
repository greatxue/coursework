import pandas as pd
import numpy as np
from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

data = pd.DataFrame([[1, 1, 709], [1, 1, 659],   [1, 2, 713], [1, 2, 726],  [1, 3, 660], [1, 3, 645],
                     [2, 1, 668], [2, 1, 685],   [2, 2, 722], [2, 2, 740],  [2, 3, 692], [2, 3, 720],
                     [3, 1, 659], [3, 1, 685],   [3, 2, 666], [3, 2, 684],  [3, 3, 678], [3, 3, 678], 
                     [4, 1, 698], [4, 1, 650],   [4, 2, 704], [4, 2, 666],  [4, 3, 686], [4, 3, 733]],
                    columns=['Brand', 'Surface', 'value'])


model = ols('value ~ C(Brand) + C(Surface) + C(Brand)*C(Surface)',
                data=data[['Brand', 'Surface', 'value']]).fit()
anovat = anova_lm(model)
print(anovat)