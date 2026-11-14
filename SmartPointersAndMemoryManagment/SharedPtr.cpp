#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i)
{
    (*i)++;
}

/// C++11; 引用计数;
int main()
{
    auto pointer0 = std::make_shared<int>(10);
    foo(pointer0);
    std::cout << *pointer0 << std::endl;

    auto pointer1 = pointer0; // 引用计数+1
    auto pointer2 = pointer0; // 引用计数+1

    int *p = pointer0.get();
    std::cout << "pointer0 use_count:" << pointer0.use_count() << std::endl;
    std::cout << "pointer1 use_count:" << pointer1.use_count() << std::endl;
    std::cout << "pointer2 use_count:" << pointer2.use_count() << std::endl;
    
    
    /// 
    pointer0.reset(); // 减少引用计数
    std::cout << "pointer1 use_count:" << pointer1.use_count() << std::endl;
    std::cout << "pointer2 use_count:" << pointer2.use_count() << std::endl;

    // std::cout << "pointer0:"<< (*pointer0) << std::endl;
    std::cout << "pointer1:"<< (*pointer1) << std::endl;
    std::cout << "pointer2:"<< (*pointer2) << std::endl;


    return 0;
}