#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

 /* int main()
{
    int a{3}, counter{0};
    std::mutex m;
    std::vector<std::thread> threads;

    for (int i{0}; i < 3; i++) {
        threads.emplace_back([a, &counter, &m]() {
            {
                std::lock_guard<std::mutex> lock(m);
                int result = a * a;
                std::cout << "Thread: " << std::this_thread::get_id()
                << " result of <*> operation is: " << result << std::endl;
                counter++;
                std::cout << "Thread: " << std::this_thread::get_id()
                << " incremented counter is: " << counter << std::endl;
            }
        });
    }
    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << "The final counter value is: " << counter << std::endl;
    std::cout << "The final value is: " << a << std::endl;

    return 0;
} */