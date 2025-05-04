#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <iostream>
#include <memory>
#include <stdexcept>
template <typename T>

class SingleLinkedList
{
    private:
    struct Node
    {
        T data;
        std::unique_ptr<Node> next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    size_t size;

    public:
    SingleLinkedList() : head(nullptr), size(0) {}

    void  checkIndex(size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("index out of range");
        }
    }


    void insertAtbeginning(const T& value)
    {
        std::unique_ptr<Node> newNode = make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void insertAtend(const T& value)
    {
        std::unique_ptr<Node> newNode = make_unique<Node>(value);
        Node *current = head.get();
        if(!current)
        {
            head = std::move(newNode);
            size++;
            return;
        }
        while (current->next != nullptr)
        {
            current = current->next.get();

        }
        current->next = std::move(newNode);
        size++;
    }

    void removeAtBeginning()
    {
        if (!head)
        {
            throw std::out_of_range("head is empty");
        }
        head = std::move(head->next);
        size--;
    }


    void removeAtEnd()
    {
        if (!head)
        {
            throw std::out_of_range("head is empty");
        }
        Node *current = head.get();
        while (current->next->next != nullptr)
        {
            current = current->next.get();
        }
        current->next.reset();
        size--;
    }

    T& operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("index out of range");
        }
        Node *current = head.get();
        for(size_t i = 0; i < index; i++)
        {
            current = current->next.get();
        }
        return current->data;
    }

    [[nodiscard]] size_t getSize() const { return size; }

    [[nodiscard]] bool isEmpty() const { return size == 0; }

    bool search(const T& value) const
    {
        Node *current = head.get();
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

friend std::ostream& operator<<(std::ostream& os, const SingleLinkedList<T> &obj)
    {
        Node *current = obj.head.get();
        os << "List data: " << std::endl;
        while (current != nullptr)
        {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }

    void insertAtindex(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("index out of range");
        }
        if (index == 0) {
            insertAtbeginning(value);
        } else if (index == size) {
            insertAtend(value);
        } else {
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
            Node* current = head.get();
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next.get();
            }
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            size++;
        }
    }

    void removeAtindex(size_t index) {
        checkIndex(index);
        if (index == 0) {
            removeAtBeginning();
        } else if (index == size - 1) {
            removeAtEnd();
        } else {
            Node* current = head.get();
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next.get();
            }
            current->next = std::move(current->next->next);
            size--;
        }
    }

};




#endif //SINGLELINKEDLIST_H