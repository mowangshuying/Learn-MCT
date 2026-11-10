#include <iostream>
#include <vector>
#include <initializer_list>

class Foo 
{
public:
    Foo(int a, int b) : m_a(a), m_b(b)
    {

    }
public:
    int m_a;
    int m_b;
};

class MagicFoo 
{
public:
    MagicFoo(std::initializer_list<int> list)
    {
        for (std::initializer_list<int>::iterator iter = list.begin(); iter != list.end(); iter++)
        {
            m_vec.push_back(*iter);
        }
    }
public:
    std::vector<int> m_vec;
};

int main(int argc, char** argv)
{
    /// before c++ 11;
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]" << arr[0] << std::endl;
    std::cout << "foo:" << foo.m_a << "," << foo.m_b << std::endl;
    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        std::cout << (*iter) << ","; 
    }

    std::cout << std::endl;

    /// after c++11;
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo:";
    for (std::vector<int>::iterator iter = magicFoo.m_vec.begin(); iter != magicFoo.m_vec.end(); iter++)
    {
        std::cout << (*iter) << ",";
    }
    std::cout << std::endl;

    Foo foo1{3, 4};
    std::cout << "foo1:" << foo1.m_a << "," << foo1.m_b << std::endl;

    return 0;
}