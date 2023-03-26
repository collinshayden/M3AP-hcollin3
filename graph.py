import matplotlib.pyplot as plt
import numpy as np

with open('data/bubble.txt', 'r') as bubble:
    data = bubble.readlines()
bubble.close()
for i in range(len(data)):
    data[i] = data[i].rstrip().split(',')
    data[i] = list(map(int, data[i]))

reads = []
writes = []
for i in data:
    reads.append(i[0])
    writes.append(i[1])

print(reads)
print(writes)
x = np.linspace(0, 1000, 10)

plt.plot(x, reads, x, writes)
plt.show()