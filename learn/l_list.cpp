
#include <iostream>
#include <list>

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
