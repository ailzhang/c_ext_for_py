#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "util.h"

namespace py = pybind11;

PYBIND11_MODULE(sum_from_pybind11, m) {
  m.def(
      "my_sum",
      [](std::vector<int> &data) {
        int sum = my_sum(data.size(), data.data());
        return sum;
      },
      "");
}
