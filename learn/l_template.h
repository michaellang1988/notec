#ifndef L_TEMPLATE_H
#define L_TEMPLATE_H
#include <type_traits> 
void test_template();

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type test_many_template(T1 a, T2 b);
#endif