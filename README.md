# Compile for ctypes demo
I didn't bother writing a proper `build_ext` for this so manual copy is required.

```
mkdir build
cd build
cmake .. && make
cp *.so ../
```

# Compile pybind11 & cpython demo
```
python setup.py build && pip install -e .
```

# Run

```
python main.py
```

# References
- https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C
- https://github.com/pybind/python_example
- https://pgi-jcns.fz-juelich.de/portal/pages/using-c-from-python.html
- https://gist.github.com/physacco/2e1b52415f3a964ad2a542a99bebed8f
- https://scipy-lectures.org/advanced/interfacing_with_c/interfacing_with_c.html#id1
- https://stackoverflow.com/questions/22458298/extending-python-with-c-pass-a-list-to-pyarg-parsetuple
