#include <iostream>
#include <future>
#include <thread>

int main(int argc, char** argv)
{
    std::packaged_task<int()> task([](){
        return 7;
    });

    std::future<int> result = task.get_future();

    std::thread (std::move(task)).detach();
    
    std::cout << "wating..." << std::endl;
    result.wait();
    
    std::cout << "done!" << std::endl;
    std::cout << "future result is:" << result.get() << std::endl;

    
    return 0;
}