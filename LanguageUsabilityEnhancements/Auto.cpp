#include <iostream>
#include <vector>
#include <initializer_list>

class MagicFoo 
{
public:
    MagicFoo(std::initializer_list<int> list)
    {
        /// after c++11;
        for (auto iter = list.begin(); iter != list.end(); iter++)
        {
            m_vec.push_back(*iter);
        }
    }
public:
    std::vector<int> m_vec;
};

///c++20; 一般函数支持传参数
int auto20(auto x, auto y)
{
    return x+ y;
}

int main(int argc, char** argv)
{
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo:";
    for (auto iter = magicFoo.m_vec.begin(); iter != magicFoo.m_vec.end(); iter++)
    {
        std::cout << *iter << ", ";
    }
    std::cout << std::endl;

    // auto i = 5;
    // auto arr = new auto(10);

    /// lambda表达式中函数传参
    auto add14 = [](auto x, auto y) -> int {
            return x + y;
        };


    // auto 还无法推导数组
}