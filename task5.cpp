#include "task5.h"

void producer(safeQueue& queue)
{
    for (int i = 0; i < 5; i++)
    {
        queue.enqueue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void consumer(safeQueue& queue)
{
    for (int i = 0; i < 5; i++)
    {
        queue.dequeue();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    safeQueue queue;

    std::thread producer_thread(producer, std::ref(queue));
    std::thread consumer_thread(consumer, std::ref(queue));

    producer_thread.join();
    consumer_thread.join();

    return 0;
}