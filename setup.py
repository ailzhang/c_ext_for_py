# DO NOT reorder these imports due to monkey-patch
from pybind11.setup_helpers import Pybind11Extension
from distutils.core import setup, Extension
import subprocess

cpython_mod = Extension('sum_from_cpython', sources = ['src/sum_cpython.c'])
pybind_mod = Pybind11Extension('sum_from_pybind11', sources = ['src/sum_pybind11.cpp'])

subprocess.run(["swig", "-outcurrentdir", "-python", "src/swig_sum.i"])
swig_mod = Pybind11Extension('_swig_example', sources = ['swig_sum_wrap.c', 'src/sum.c'])

setup (name = 'demo',
        version = '0.0',
        description = 'This is a demo package',
        ext_modules = [cpython_mod, pybind_mod, swig_mod],
        py_modules = ['swig_example']
        )
