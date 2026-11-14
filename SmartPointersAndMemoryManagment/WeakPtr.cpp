#include <iostream>
#include <memory>

struct A;
struct B;

struct A
{
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

    std::weak_ptr<B> pointer;
};


struct B
{
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }

    std::shared_ptr<A> pointer;
};

int main(int argc, char** argv)
{
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->pointer = b;
    b->pointer = a;

    std::cout << "a.use_count:" << a.use_count() << ", b.use_count:" << b.use_count() << std::endl;
    
    return 0;
}
