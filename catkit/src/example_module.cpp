// example.cpp
#include <pybind11/pybind11.h>
#include <example/example.cpp>

// namespace py = pybind11;

PYBIND11_MODULE(example, m)
{
    m.def("add", &add, "A function that adds two numbers");
}