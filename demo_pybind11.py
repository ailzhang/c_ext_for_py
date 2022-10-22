from pybind11_demo import add, Response, count_strings

print(add(1, 2))

a = Response()
print(a.status) # prints "200"
# a.status = 100
# The line above will error out as expected
# Traceback (most recent call last):
#   File "demo_pybind11.py", line 7, in <module>
#     a.status = 100
# AttributeError: can't set attribute

print('count_strings: ', count_strings(["hello", "world"]))