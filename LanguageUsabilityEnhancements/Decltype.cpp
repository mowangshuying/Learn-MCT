#include <iostream>
#include <type_traits>


// c++11;
template<typename R, typename T, typename U>
R add(T x, U y)
{
    return x + y;
}

// 尾部返回值推导
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}

// c++14;
template<typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}

int main()
{
    /// c++11;
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    // after c++11;
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value)
    {
        std::cout << "w is double" << std::endl;
    }

    // after c++14;
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q:" << q << std::endl;

    // decltype(auto)
}