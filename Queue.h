#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
template <typename T>

class Queue
{
private:
    T* array;
    int capacity;;
    int front;
    int rear;
    int size;

public:
    explicit Queue(int capacity) : capacity{capacity}, front{0}, rear{-1}, size{0}
    {
        array = new T[capacity];
    }
    ~Queue() {
        delete[] array;
    }

    [[nodiscard]] bool isEmpty() const
    {
        return size == 0;
    }

    [[nodiscard]] bool isFull() const
    {
        return size == capacity;
    }

    void Enqueue(const T& element)
    {
        if (isFull())
        {
            std::cout << "Queue is full." << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = element;
        size++;
    }

    T Dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            exit(1);
        }
        T item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    T Peek() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            exit(1);
        }
        return array[front];
    }
};

#endif //QUEUE_H
