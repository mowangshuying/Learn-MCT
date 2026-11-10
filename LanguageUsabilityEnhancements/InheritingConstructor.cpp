#include <iostream>

class Base 
{
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

class SubClass : public Base 
{
public:
    using Base::Base;
};

int main()
{
    SubClass s(3);
    std::cout << s.m_value1 << std::endl;
    std::cout << s.m_value2 << std::endl;
}