#include <iostream>

void mayThrow()
{
    throw true;
}

auto nonBlockThrow = []{ mayThrow(); };

void noThrow() noexcept 
{
    return;
}

auto blockThrow = []() noexcept { noThrow(); };

int main()
{
    std::cout << std::boolalpha
        << "mayThrow noexcept? " << noexcept(mayThrow()) << std::endl           // except;
        << "noThrow noexcept? "  << noexcept(noThrow()) << std::endl            // noexcept;          
        << "lmayThrow noexcept? "  << noexcept(blockThrow()) << std::endl       // noexcept;
        << "lnoThrow noexcept? "  << noexcept(nonBlockThrow()) << std::endl;    // except;


    try
    {
        mayThrow();
    }
    catch(...)
    {
        std::cout << "catch except: mayThrow()" << std::endl;
    }
    
}