import sum_from_ctypes
import sum_from_pybind11
import sum_from_cpython
import time

N = 50

def timed_run(func, name):
    a = [1] * 100
    start = time.time()
    for _ in range(N):
        func(a)
    print(f'{name} took {(time.time() - start) / N}s')


timed_run(sum_from_ctypes.my_sum, 'ctypes')
timed_run(sum_from_pybind11.my_sum, 'pybind')
timed_run(sum_from_cpython.my_sum, 'cpython')

