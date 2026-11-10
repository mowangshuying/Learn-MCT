#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<int> vec = {1, 2, 3, 4};
    
    /// before c++ 17;
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end())
    {
        (*itr) = 3;
    }

    /// print vec;
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << (*itr) << ",";
    }
    std::cout << std::endl;

    /// after c++17;
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
    {
        (*itr) = 4;
    }

    /// print vec;
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << (*itr) << ",";
    }
    std::cout << std::endl;

    return 0;
}