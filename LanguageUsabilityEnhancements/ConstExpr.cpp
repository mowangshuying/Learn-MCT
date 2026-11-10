#include <iostream>

/// cpp编译期表达式，编译时候就把一些表达式直接优化成值嵌入到程序中

#include <iostream>
#define LEN 10

int fooLen() 
{
    int i = 2;
    return 2;
}

constexpr int fooConstExprLen()
{
    return 5;
}

constexpr int fibonacci(const int n) 
{
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n - 2);
}

int main(int argc, char** argv)
{
    char arr1[10];
    char arr2[LEN];
    int len1 = 10;
    // char arr3[len1]; // error

    const int len2 = len1 + 1;
    constexpr int len3 = 1 + 2 + 3;

    // char arr4[len2]; //error;
    char arr5[len3];
    std::cout << fibonacci(10) << std::endl;

    return 0;
}