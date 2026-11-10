#include <iostream>

// 委托构造
// C++ 11引入委托构造允许一个构造函数把初始化工作委托给同一个类中的另外一个构造函数，从而消除这种重复

class Base {
public:
    Base()
    {
        m_value1 = 1;
    }

    Base(int value) : Base()
    {
        m_value2 = value;
    }
public:
    int m_value1;
    int m_value2;
};

int main()
{
    Base b(2);
    std::cout << b.m_value1 << std::endl;
    std::cout << b.m_value2 << std::endl;
}