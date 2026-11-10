#include "foo.h"
#include <iostream>
#include <functional>

int main() 
{
    // 1. std::cout << "Result from C code:" << add(1,2);
    // 2. out = std::ref
    // 3. out.get() << "\n"
    [out = std::ref(std::cout << "Result from C code:" << add(1, 2))]() 
        {
            out.get() << "\n";
        }();
}

