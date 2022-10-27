#include <Python.h>
#include <stdio.h>

// Module method definitions
static PyObject *my_sum_from_cpython(PyObject *self, PyObject *args) {
  PyObject *pList;
  PyObject *pItem;
  Py_ssize_t n;
  int i;
  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list");
    return NULL;
  }
  n = PyList_Size(pList);
  long sum = 0;
  for (i = 0; i < n; i++) {
    pItem = PyList_GetItem(pList, i);
    if (!PyLong_Check(pItem)) {
      return NULL;
    }
    sum += PyLong_AsLong(pItem);
  }
  return Py_BuildValue("l", sum);
}
// Method definition object for this extension, these argumens mean:
// ml_name: The name of the method
// ml_meth: Function pointer to the method implementation
// ml_flags: Flags indicating special features of this method, such as
//          accepting arguments, accepting keyword arguments, being a
//          class method, or being a static method of a class.
// ml_doc:  Contents of this method's docstring
static PyMethodDef sum_from_cpython_methods[] = {
    {"my_sum", my_sum_from_cpython, METH_VARARGS, ""}, {NULL, NULL, 0, NULL}};

// Module definition
// The arguments of this structure tell Python what to call your extension,
// what it's methods are and where to look for it's method definitions
static struct PyModuleDef sum_from_cpython_definition = {
    PyModuleDef_HEAD_INIT, "sum_from_cpython",
    "A Python module that prints 'sum_from_cpython world' from C code.", -1,
    sum_from_cpython_methods};

// Module initialization
// Python calls this function when importing your extension. It is important
// that this function is named PyInit_[[your_module_name]] exactly, and matches
// the name keyword argument in setup.py's setup() call.
PyMODINIT_FUNC PyInit_sum_from_cpython(void) {
  Py_Initialize();
  return PyModule_Create(&sum_from_cpython_definition);
}
