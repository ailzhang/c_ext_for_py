import sum_from_pybind11
import sum_from_cpython
import time
import ctypes
from swig_example import my_add

sum_from_ctypes = ctypes.CDLL('libsum_from_ctypes.so')
sum_from_ctypes.my_sum.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))

N = 200
WARMPUP = 10


def run_once(func, x, n=None):
    start = time.time()
    if n is not None:
        func(n, x)
    else:
        func(x)
    return time.time() - start


def timed_run(func, name):
    acc = 0.
    for i in range(N):
        a = [1] * i
        if name == 'ctypes':
            n = ctypes.c_int(i)
            arr_type = ctypes.c_int * i
            x = arr_type(*a)
            acc += run_once(func, x, n)
        else:
            acc += run_once(func, a)
    print(f'{name} took {acc / N}s')


for _ in range(WARMPUP):
    n = 1
    data = [1] * n
    arr_type = ctypes.c_int * n
    run_once(sum_from_pybind11.my_sum, data)
    run_once(sum_from_ctypes.my_sum, arr_type(*data), ctypes.c_int(n))
    run_once(sum_from_cpython.my_sum, data)

timed_run(sum_from_pybind11.my_sum, 'pybind')
timed_run(sum_from_ctypes.my_sum, 'ctypes')
timed_run(sum_from_cpython.my_sum, 'cpython')

print('swig demo returns result: ', my_add(1, 2))
