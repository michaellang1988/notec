#include <iostream>
#include "learn/l_template.cpp"
#include "learn/l_list.cpp"
#include "learn/l_struct_1.cpp"

int main()
{
    test_template();
    test_list();
    auto res = test_many_template(10, 20.5);
    std::cout << res << std::endl;
    std::cout << "----------------" << std::endl;
    test_pulse();
}
