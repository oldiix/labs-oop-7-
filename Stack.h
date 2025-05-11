#ifndef STACK_H
#define STACK_H
#include <iostream>
template <typename T>

class Stack
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* top;
    size_t size;

    public:
    Stack() : top(nullptr) {}
    ~Stack()
    {
        while (!isEmpty())
        {
            Pop();
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    T Peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            exit(1);
        }
        return top->data;
    }

    T Pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            exit(1);
        }
        T data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size --;
        return data;
    }

    void Push(const T& element)
    {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        size++;
    }
};

#endif //STACK_H
