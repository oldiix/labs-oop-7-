#ifndef TASK5_H
#define TASK5_H
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

class safeQueue {
private:
    std::queue<int> queue;
    std::mutex mutex;
    std::condition_variable condition;
    const unsigned int MAX_SIZE = 5;
public:
    void enqueue(int value)
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [this]() { return queue.size() < MAX_SIZE; });

        queue.push(value);
        std::cout << "Produced: " << value << " (size: " <<queue.size() <<  ")\n";

        condition.notify_one();
    }

    int dequeue()
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [this]() { return !queue.empty(); });

        int value = queue.front();
        queue.pop();
        std::cout << "Consumed: " << value << "(size: " << queue.size() <<  ")\n";

        condition.notify_one();
        return value;
    }
};





#endif //TASK5_H
