import numpy as np

# Исходный массив
arr = np.array([3, 2, 3, 3, 1])

# Находим все индексы максимального элемента
max_ind = np.where(arr == arr.max())[0]

# Выбираем n-й индекс
n = int(input())

#Берём n-й элемент из max_ind
if n < len(max_ind):

    ind = max_ind[n]
    print(ind)

else:

    print(f"Максимальных элементов меньше {n + 1}")