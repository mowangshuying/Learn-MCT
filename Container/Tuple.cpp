#include <tuple>
#include <iostream>
#include <variant>

std::tuple<std::string, char, double> getStudent(int id)
{
    if (id == 1)
    {
        return std::make_tuple("Alice", 'A', 3.8);
    }
    else if (id == 2)
    {
        return std::make_tuple("Bob", 'B', 2.9);
    }
    return std::make_tuple("Unknown", 0, 0.0);
}

int main()
{
    auto s0 = getStudent(1);
    std::cout << "S1:" << std::get<0>(s0) << ", " << std::get<1>(s0) << ", " << std::get<2>(s0) << std::endl;

    std::string name;
    char grade;
    double gpa;
    std::tie(name, grade, gpa) = getStudent(1);
    std::cout << "S2:" << name << ", " << grade << ", " << gpa << std::endl;

    /// C++ 14增加了使用类型获取数据，但是如果有多个相同数据则不可以。
    std::cout << "S2:" << "name is" << std::get<std::string>(getStudent(2)) << std::endl;

    /// std::get 依赖编译期常量，所以下列方式不合法。
        /// int index = 1; std::get<index>(t)

    /// 合并元组
    auto t1 = std::tuple_cat(getStudent(1), getStudent(2));
    std::cout << "S3:" << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << std::endl;
    std::cout << "S3:" << std::get<3>(t1) << ", " << std::get<4>(t1) << ", " << std::get<5>(t1) << std::endl;
}