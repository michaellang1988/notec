// #include "l_template.h"
#include <iostream>
#include <string>
#include <type_traits>


template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

void test_template()
{
    int i = 39;
    int j = 20;
    std::cout << "Max(i, j): " << Max(i, j) << std::endl;

    double f1 = 13.5;
    double f2 = 20.7;
    std::cout << "Max(f1, f2): " << Max(f1, f2) << std::endl;

    std::string s1 = "Hello";
    std::string s2 = "World";
    std::cout << "Max(s1, s2): " << Max(s1, s2) << std::endl;
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type test_many_template(T1 a, T2 b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
