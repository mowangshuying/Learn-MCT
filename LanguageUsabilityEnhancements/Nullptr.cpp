#include <iostream>
#include <type_traits>

void foo(char* )
{
    std::cout << "foo(char*) is called." << std::endl;
}

void foo(int i) 
{
    std::cout << "foo(int) is called" << std::endl;
}

int main()
{
    if(std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;

    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void*)0" << std::endl;

    if (std::is_same<decltype(NULL), decltype(nullptr)>::value)
        std::cout << "NULL == nullptr" << std::endl;

    foo(NULL);
    foo(nullptr);
    return 0;
}