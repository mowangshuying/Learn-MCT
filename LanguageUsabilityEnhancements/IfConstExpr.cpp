#include <iostream>
#include <type_traits>

// c++17 
// if constexpr
template<typename T>
auto printTypeInfo(const T& t)
{
    if constexpr (std::is_integral<T>::value)
    {
        return t + 1;
    }
    else
    {
        return t + 0.001;
    }
}

int main(int argc, char** argv)
{
    std::cout << printTypeInfo(5) << std::endl;
    std::cout << printTypeInfo(3.14) << std::endl;
}