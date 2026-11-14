#include <cstddef>
#include <iostream>

int main()
{
    std::byte b1 {0b0000'1111};
    std::byte b2 {0b1111'0000};
    std::byte b3 = b1 | b2; // 位或运算
    std::byte b4 = b1 & b2; // 位与运算

    std::cout << std::to_integer<int>(b3) << std::endl;
    std::cout << std::to_integer<int>(b4) << std::endl;
}