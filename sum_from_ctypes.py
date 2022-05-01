import ctypes

_sum = ctypes.CDLL('libsum_from_ctypes.so')
_sum.my_sum.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))

def my_sum(numbers):
    global _sum
    num_numbers = len(numbers)
    array_type = ctypes.c_int * num_numbers
    result = _sum.my_sum(ctypes.c_int(num_numbers), array_type(*numbers))
    return int(result)
