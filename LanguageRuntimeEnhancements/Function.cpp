#include <iostream>
#include <functional>

/// 函数包装器
/// C++中可以被调用东西其实形态各异：普通函数，函数指针，Lambda表达式以及任何重载的operator()的对象，
/// 他们类型彼此不同, 很难用一种统一方式来保存和传递。std::function就是为解决这类问题产生的。
/// 它是一个类型安全的函数调用容器，能够统一存储，复制并调用任意可以调用的目标，从而让我们能像处理普通
/// 函数那样去处理函数。

using foo = void(int);

void functional(foo f)
{
    f(1);
}


int foo1(int para)
{
    return para;
}

int main()
{
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    functional(f);  // 传递闭包对象，隐式转换为foo*类型的函数指针值
    f(1);           // lambda表达式调用

    std::function<int(int)> func1 = foo1;
    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return 1 + value + important;
    };

    std::cout << func1(10) << std::endl;
    std::cout << func2(10) << std::endl;
}