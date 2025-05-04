#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <memory>
#include <stdexcept>
using namespace std;
template <typename T>

class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        shared_ptr<Node> previous;
        shared_ptr<Node> next;
        explicit Node(const T& value) : data(value), previous(nullptr), next(nullptr) {}
    };
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    size_t size;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void checkIndex(size_t index)
    {
        if (index >= size)
        {
            throw out_of_range("index is out of range");
        }
    }

    void insertAtBeginning(const T& value)
    {
        shared_ptr<Node> newNode = make_shared<Node>(value);
        if(!head)
        {
            head = tail = newNode;
        } else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(const T& value)
    {
        shared_ptr<Node> newNode = make_shared<Node>(value);
        if(!tail)
        {
            head = tail = newNode;
        } else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    void removeAtBeginning()
    {
        if(!head)
        {
            return;
        }
        if (head == tail)
        {
            head = tail = nullptr;
        } else
        {
            head = head -> next ;
            head->previous.reset();
        }
        size--;
    }

    void removeAtEnd(){
        if (!tail) {
            return;
        }
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->previous;
            tail->next.reset();
        }
        --size;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        Node *current = head.get();
        for (size_t i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    [[nodiscard]] size_t getSize() const {
        return size;
    }

    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }

    bool search(const T& value){
        shared_ptr<Node> current = head;
        if (!head){
            throw out_of_range("List is empty");
        }
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const DoublyLinkedList<T> &obj) {
        Node *current = obj.head.get();
        os << "List data: " << endl;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    }

    void insertAtIndex(size_t index, const T& value){
        checkIndex(index);
        if (index == 0) {
            insertAtBeginning(value);
        }
        if (index == size) {
            insertAtEnd(value);
        }
        shared_ptr<Node> newNode = make_shared<Node>(value);
        shared_ptr<Node> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        ++size;
    }

    void removeAtIndex(size_t index){
        checkIndex(index);
        if (index == 0) {
            head = head->next;
            if (head) {
                head->previous.reset();
            } else {
                tail.reset();
            }
        } else if (index == size - 1) {
            tail = tail->previous;
            tail->next.reset();
        } else {
            shared_ptr<Node> current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }
        --size;
    }

};


#endif //DOUBLYLINKEDLIST_H