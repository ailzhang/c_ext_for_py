#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


namespace py = pybind11;

int add(int a, int b) {
  return a + b;
}
PYBIND11_MODULE(pybind11_demo, m) {
  m.def("add", &add, "Binary add");
}
