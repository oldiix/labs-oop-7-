#ifndef INPUTRESTRICTEDQUEUE_H
#define INPUTRESTRICTEDQUEUE_H
#include <iostream>
template <typename T>

class InputRestrictedQueue
{
    private:
    struct Node
    {
        T data;
        Node* next;
        Node* previous;

        Node(const T& data) : data(data), next(nullptr), previous(nullptr) {}
    };
    Node* front;
    Node* rear;

    public:
    InputRestrictedQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueRear(const T& element)
    {
        Node* newNode = new Node(element);
        std::cout << "Insert the element at the back of the queue: " << element << std::endl;
        if (isEmpty())
        {
            front = rear = newNode;
        } else
        {
            rear->next = newNode;
            newNode->previous = rear;
            rear = newNode;
        }
    }

    T dequeueFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            exit(1);
        }
        T element = front->data;
        Node* temp = front;
        std::cout << "Deleting element at the front: " << element << std::endl;
        front = front->next;
        if (front) front->previous = nullptr;
        else rear = nullptr;
        delete temp;
        return element;
    }

    T dequeueRear()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            exit(1);
        }
        T element = rear->data;
        Node* temp = rear;
        std::cout << "Deleting element at the back: " << element << std::endl;
        rear = rear->previous;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete rear;
        return element;
    }

    void display() const {
        Node* temp = front;
        while (temp) {
            std::cout << temp->data;
            if (temp->next) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};



#endif //INPUTRESTRICTEDQUEUE_H
