#include <iostream>
#include <tuple>
#include <map>

std::tuple<int, double, std::string> f() 
{
    return std::make_tuple(1, 2.3, "456");
}

int main(int argc, char** argv)
{
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;

    std::map<std::string, int> scores{{"alice", 90}, {"blob", 80}};
    for (const auto& [name, score] : scores) 
    {
        std::cout << name << ":" << score << "\n";
    }
}