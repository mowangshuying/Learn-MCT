#include <iostream>


enum class NewEnum : unsigned int 
{
    value1,
    value2,
    value3 = 100,
    value4 = 100,
};

int main()
{
    if (NewEnum::value3 == NewEnum::value4)
    {
        std::cout << "NewEnum::value3 == NewEnum::Value4" << std::endl;
    }

    return 0;
}