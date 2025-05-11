#include <iostream>
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "SingleLinkedList.h"
#include "Stack.h"
#include "InputRestrictedQueue.h"

int main()
{
    try
    {
        SingleLinkedList<int> list;

        list.insertAtbeginning(9);
        list.insertAtbeginning(8);
        list.insertAtbeginning(7);

        cout << "The list after adding elements at the beginning: " << endl;
        cout << list << endl;

        list.insertAtend(17);
        list.insertAtend(18);
        list.insertAtend(19);

        cout << "The list after adding elements at the end: " << endl;
        cout << list << endl;

        list.removeAtBeginning();
        list.removeAtEnd();

        cout << "The list after removing elements at the beginning and at the end: " << endl;
        cout << list << endl;

        int searchValue = 9;
        if (list.search(searchValue))
        {
            cout << searchValue << " is found in the list." << endl;
        } else
        {
            cout << searchValue << " is not found in the list." << endl;
        }

        size_t index = 1;
        int insertValue = 77;
        list.insertAtindex(index, insertValue);

        cout << "The list after inserting elements at the index: " << index << ":" << endl;
        cout << list << endl;


        size_t removeIndex = 3;
        list.removeAtindex(removeIndex);

        cout << "The list after removing elements at the index: " <<  removeIndex << ":" << endl;
        cout << list << endl;

    } catch (const std::exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    } try
    {
        DoublyLinkedList<int> list;

        list.insertAtBeginning(77);
        list.insertAtBeginning(66);
        list.insertAtBeginning(55);

        list.insertAtEnd(88);
        list.insertAtEnd(99);

        cout << "Data list: " << endl;
        cout << list << endl;

        list.removeAtBeginning();
        list.removeAtEnd();

        cout << "Data list after removing front and back elements: " << endl;
        cout << list << endl;

        int searchValue = 88;
        if (list.search(searchValue))
        {
            cout << searchValue << " is found in the list." << endl;
        } else
        {
            cout << searchValue << " is not found in the list." << endl;
        }

        list.insertAtIndex(1,68);

        cout << "Data list after inserting elements at index 2: " << endl;
        cout << list << endl;


        list.removeAtIndex(2);
        cout << "Data list after removing element at index 2: " << endl;
        cout << list << endl;

    } catch (const std::exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    Queue<int> queue(3);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    cout << "\n===== Queue Section =====" << endl;
    cout << "Initial front element: " << queue.Peek() << endl;
    cout << "Element dequeued: " << queue.Dequeue() << endl;
    cout << "New front element: " << queue.Peek() << endl;


    Stack<string> stack;
    stack.Push("Bonjour,");
    stack.Push(" mes amis!");
    cout << "\n===== Stack Section =====" << endl;
    cout << "Top element: " << stack.Peek() << endl;
    cout << "Pop: " << stack.Pop() << endl;
    cout << "Top element after pop: " << stack.Peek() << endl;

    InputRestrictedQueue<string> q;
    cout << "\n===== Input Restricted Queue Section =====" << endl;
    q.enqueueRear("tarantino");
    q.enqueueRear("nolan");
    q.enqueueRear("scorsese");
    cout << "Queue after adding elements at the back: " << endl;
    q.display();

    q.dequeueFront();
    cout << "Queue after removing front: " << endl;
    q.display();

    q.dequeueRear();
    cout << "Queue after removing back: " << endl;
    q.display();

}
