#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <unistd.h>
#include <iostream>

namespace py = pybind11;

int add(int a, int b) { return a + b; }

struct Response {
  int status;
  std::string reason;
  std::string text;

  Response(int status, std::string reason, std::string text = " ")
      : status(status), reason(std::move(reason)), text(std::move(text)) {}

  Response() : Response(200, "OK") {}
};

PYBIND11_MODULE(pybind11_demo, m) {
  py::class_<Response>(m, "Response")
      .def(py::init<>())
      .def(py::init<int, std::string>())
      .def(py::init<int, std::string, std::string>())
      .def_readonly("status", &Response::status)
      .def_readonly("reason", &Response::reason)
      .def_readonly("text", &Response::text);
  m.def("count_strings", [](py::list list) {
    int n = 0;
    for (auto item : list) {
      if (py::isinstance<py::str>(item)) {
        n++;
      }
    }
    return n;
  });
  m.def(
      "long_running", []() { sleep(10); std::cout << "Done" << std::endl; },
      py::call_guard<py::gil_scoped_release>());
  m.def("tp", [](int x) { return "int"; });
  m.def("tp", [](float x) { return "float"; });
  m.def("add", &add, "Binary add");
}
