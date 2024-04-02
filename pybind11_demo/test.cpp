#include <pybind11/pybind11.h>
# include <Python.h>
// template <typename T>
// T add(T a, T b)
// {
//     return a + b;
// }

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pyqc, m)
{
    m.doc() = "pybind11 test";
    m.def("add", &add, "a add func");
}