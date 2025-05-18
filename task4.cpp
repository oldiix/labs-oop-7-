#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void thread1()
{
    std::cout << "Thread 1 is trying to lock mutex1" << std::endl;
    mutex1.lock();
    std::cout << "Thread 1: Mutex1 is locked." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Thread 1 is trying to lock mutex2" << std::endl;
    mutex2.lock();
    std::cout << "Thread 1: Mutex2 is locked." << std::endl;
    std::cout << "Thread 1: Critical section execution..." << std::endl;

    mutex2.unlock();
    mutex1.unlock();
}

void thread2()
{
    std::cout << "Thread 2 is trying to lock mutex2" << std::endl;
    mutex2.lock();
    std::cout << "Thread 2: Mutex2 is locked." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Thread 2 is trying to lock mutex1" << std::endl;
    mutex1.lock();
    std::cout << "Thread 2: Mutex1 is locked." << std::endl;
    std::cout << "Thread 2: Critical section execution..." << std::endl;

    mutex1.unlock();
    mutex2.unlock();
}

void fixed_thread1()
{
    std::scoped_lock lock(mutex1, mutex2);
    std::cout << "Thread 1: Critical section execution..." << std::endl;
}

void fixed_thread2()
{
    std::scoped_lock lock(mutex1, mutex2);
    std::cout << "Thread 2: Critical section execution..." << std::endl;
}
/* int main()
{
    std::thread thread1(fixed_thread1);
    std::thread thread2(fixed_thread2);

    thread1.join();
    thread2.join();

    std::cout << "Program execution is completed." << std::endl;
    return 0;
} */