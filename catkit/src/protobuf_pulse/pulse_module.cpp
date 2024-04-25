// example.cpp
#include <pybind11/pybind11.h>
#include <pulse.cpp>
// namespace py = pybind11;

PYBIND11_MODULE(_protobuf_pulse, m)
{
    m.def("test", &test, "A function that adds two numbers");
}