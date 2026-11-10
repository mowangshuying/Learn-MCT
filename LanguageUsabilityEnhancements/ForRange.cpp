#include <iostream>
#include <vector>
#include <algorithm>

/// C++ 11;
int main()
{
    std::vector<int> vec = {1, 2, 3, 4};
    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
        (*itr) = 4;

    for (auto element : vec)
    {
        std::cout << element << ",";
    }
    std::cout << std::endl;

    for (auto element : vec)
    {
        std::cout << element << ",";
    }
    std::cout << std::endl;
}