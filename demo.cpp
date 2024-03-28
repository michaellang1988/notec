#include <string>
#include <iostream>
#include <list>
using namespace std;

template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

void test_template()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

void test_list()
{
    std::list<int> test_list;
    test_list.push_back(20);
    test_list.push_front(10);
    test_list.push_back(30);

    for (auto it = test_list.begin(); it != test_list.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    test_list.pop_back();

    auto it = ++test_list.begin();
    test_list.insert(it, 15);

    std::cout << "test test list";
    for (int ele : test_list)
    {
        std::cout << ele << " ";
    }

    std::cout << std::endl;
    std::cout << "\n"
              << std::endl;
}

int main()
{
    test_list();
    return 0;
}