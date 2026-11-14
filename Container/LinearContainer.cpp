#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "after push_back 3 elements" << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
    }

    std::cout << "after push_back 100 elements" << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.clear();
    std::cout << "after clear" << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    /// shrink: 收缩
    /// fit： 适合
    /// 收缩到合适
    vec.shrink_to_fit();
    std::cout << "after shrink_to_fit" << std::endl;
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    return 0;
}