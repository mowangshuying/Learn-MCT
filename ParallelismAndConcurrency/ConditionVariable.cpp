#include <queue>
#include <chrono>
#include <mutex>
#include <iostream>
#include <condition_variable>

int main(int argc, char** argv)
{
    std::queue<int> producedNums;

    std::mutex mtx;
    std::condition_variable cv;

    bool notified = false;

    auto producer = [&]() {
        for (int i = 0; ; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            std::unique_lock<std::mutex> lock(mtx);

            producedNums.push(i);
            notified = true;
            cv.notify_all();
        }
    };

    auto consumer = [&]() {
        std::unique_lock<std::mutex> lock(mtx);
        while (!notified)
        {
            cv.wait(lock);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        lock.lock();
        while (!producedNums.empty())
        {
            std::cout << "consuming" << producedNums.front() << std::endl;
            producedNums.pop();
        }
        
        notified = false;
    };

    std::thread p(producer);

    std::thread cs[2];
    for (int i = 0; i < 2; i++)
    {
        cs[i] = std::thread(consumer);
    }
    p.join();

    for (int i = 0; i < 2; i++)
    {
        cs[i].join();
    }

    return 0;
}