import matplotlib.pyplot as plt
import numpy as np

m = 10.092
c = 14.195

x = np.linspace(0, 100, 100)  
y = m * x + c

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
plt.title('y = 10.092x + 14.195')

plt.show()