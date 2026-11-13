#include <iostream>

class A
{
public:
    A():pointer(new int(1))
    {
        std::cout << "A()" << std::endl;
    }

    A(A& a) : pointer(new int (*a.pointer))
    {
        std::cout << "A(A& a)" << std::endl;
    }

    A(A&& a) : pointer(a.pointer)
    {
        std::cout << "A(A&& a)" << std::endl;
        a.pointer = nullptr;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
        delete pointer;
    }
public:
    int* pointer;
};


A returnRvalue(bool test)
{
    A a,b;
    if (test)
        return a;
    else
        return b; 
}

int main()
{
    A obj = returnRvalue(true);
    std::cout << "obj:" << *obj.pointer << std::endl;
}