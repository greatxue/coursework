import matplotlib.pyplot as plt
import numpy as np

m = 0.004161
c = 0.3300

x = np.linspace(0, 100, 100)  
y = m * x + c

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
plt.title('y = 0.004161x + 0.3300')

plt.show()