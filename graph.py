import matplotlib.pyplot as plt
import numpy as np

sort_types = ['bubble', 'heap', 'selection', 'quick', 'twosort']

for sort_type in sort_types:
    with open('data/' + sort_type + '.txt', 'r') as file:
        data = file.readlines()
    file.close()

    for i in range(len(data)):
        data[i] = data[i].rstrip().split(',')
        data[i] = list(map(int, data[i]))

    reads = []
    writes = []
    for i in data:
        reads.append(i[0])
        writes.append(i[1])

    x = np.linspace(0, 1000, 10)

    plt.plot(x, reads, label='reads')
    plt.plot(x, writes, label='writes')
    plt.legend(loc="upper left")
    plt.title(sort_type + ' sort read and writes')
    plt.ylabel('# of read/writes')
    plt.xlabel('input size')
    plt.savefig('images/' + sort_type + '.jpeg')
    plt.show()
    plt.close()
