#include <iostream>
#include <string>

//字面量

// 自定义字面量
std::string operator"" _wow(const char* wow, size_t len)
{
    return std::string(wow) + " wow, amazing";
}

std::string operator"" _wow(unsigned long long i)
{
    return std::to_string(i) + " wow, amazing";
}

int main(int argc, char** argv)
{
    //c++11;
    std::string str = R"(C:\File\To\Path)";
    std::cout << str << std::endl;

    auto wowstr = "abc"_wow;
    auto numstr = 1_wow;

    std::cout << "wowstr: " << wowstr << ", numstr: " << numstr << std::endl;
}