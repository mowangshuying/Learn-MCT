#include <iostream>
#include <thread> // c++11;

int main()
{
    std::thread t([](){
        std::cout << "hello, world" << std::endl;
    });

    t.join();
    return 0;
}
