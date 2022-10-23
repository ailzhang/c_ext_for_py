from pybind11_demo import add, Response, count_strings, tp, long_running
from concurrent.futures import ThreadPoolExecutor
import time

print(add(1, 2))

a = Response()
print(a.status) # prints "200"
# a.status = 100
# The line above will error out as expected
# Traceback (most recent call last):
#   File "demo_pybind11.py", line 7, in <module>
#     a.status = 100
# AttributeError: can't set attribute
pool = ThreadPoolExecutor()
for i in range(5):
  print(f'before launching {i}th long_runninng thread', time.time())
  pool.submit(long_running)
  print(f'launched {i}th long_runninng thread', time.time())

print('count_strings: ', count_strings(["hello", "world"]))

print('overloading tp function:', tp(2), tp(2.1))

