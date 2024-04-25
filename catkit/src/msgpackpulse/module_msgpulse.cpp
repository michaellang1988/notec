// example.cpp
#include <pybind11/pybind11.h>
#include <msg_test.cpp>
PYBIND11_MODULE(_msgpack_pulse, m)
{
    m.def("test_msgpack", &test_msgpack, "A function that adds two numbers");
}