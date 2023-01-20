#include <iostream>
#include<stack>

using namespace std;

class CircularQueue
{
private:
    stack<int> enqueueStack; // stack used to enqueue elements
    stack<int> dequeueStack; // stack used to dequeue elements

public:
    void enqueue(int value)
    {
        enqueueStack.push(value);
    }

    void dequeue()
    {
        // If the dequeue stack is empty, move all elements from the enqueue stack to the dequeue stack
        if (dequeueStack.empty())
        {
            while (!enqueueStack.empty())
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        // If the dequeue stack is still empty, the queue is empty and we cannot dequeue an element
        if (dequeueStack.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // Pop the top element from the dequeue stack
        dequeueStack.pop();
    }

    int front()
    {
        // If the dequeue stack is empty, move all elements from the enqueue stack to the dequeue stack
        if (dequeueStack.empty())
        {
            while (!enqueueStack.empty())
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        // If the dequeue stack is still empty, the queue is empty and we cannot return the front element
        if (dequeueStack.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // Return the top element of the dequeue stack
        return dequeueStack.top();
    }
};

int main()
{
    CircularQueue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.front() << endl; // Output: 1

    queue.dequeue();
    cout << "Front element: " << queue.front() << endl; // Output: 2

    queue.enqueue(4);
    queue.enqueue(5);

    queue.dequeue();
    cout << "Front element: " << queue.front() << endl; // Output: 3

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    cout << "Front element: " << queue.front() << endl; // Output: Queue is empty

    return 0;
}