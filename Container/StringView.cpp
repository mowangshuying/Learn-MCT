#include <iostream>
#include <string_view>


/// C++17 引入string_view;
/// string_view只有指针和长度
void printStringView(std::string_view sv)
{
    std::cout << sv << " (Size = )" << sv.size() << std::endl;
}

int main()
{
    /// 只读字符串
    std::string_view sv = "Hello, World!";
    /// sv.substr不会发生拷贝
    printStringView(sv.substr(0, 5)); // 输出 "Hello"

    std::string s = "from std::string";
    printStringView(s); // 输出 "from std::string"

    return 0;
}