#include <thread>
#include <iostream>
#include <mutex> // C++ 11;


int v = 1;

void criticalSection(int changeV)
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);
    v = changeV;
}


void criticalSectionWithUniqueLock(int changeV)
{
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);

    v = changeV;
    lock.unlock();

    // ---
    // ---

    lock.lock();
    v += 1;
}

int main()
{
    std::thread t1(criticalSectionWithUniqueLock, 2);
    std::thread t2(criticalSectionWithUniqueLock, 3);

    t1.join();
    t2.join();

    std::cout << v << std::endl;
    return 0;
}