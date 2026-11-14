#include <iostream>
#include <memory>
/// C++11;

/// C++11并没有提供make_unique函数，以下是自己实现的一个
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args)
{
    return std::unique_ptr<T>(new T(std::forward<args>(args)...));
}

struct Foo
{
    Foo()
    {
        std::cout << "Foo::Foo" << std::endl;
    }

    ~Foo()
    {
        std::cout << "Foo::~Foo" << std::endl;
    }

    void foo()
    {
        std::cout << "Foo::foo" << std::endl;
    }
};

void f(const Foo&)
{
    std::cout << "f(const Foo&)" << std::endl;
}

int main()
{
    std::unique_ptr<Foo> uptr0 = std::make_unique<Foo>();
    if(uptr0)
    {
        uptr0->foo();
    }

    {
        std::unique_ptr<Foo> uptr1(std::move(uptr0));
        f(*uptr1);

        if(uptr0)
        {
            uptr0->foo();
        }

        uptr1 = std::move(uptr0);
    }

    std::cout << "main end" << std::endl;
}
