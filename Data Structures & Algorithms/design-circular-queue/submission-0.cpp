#include <list>

class MyCircularQueue {
private:
    std::list<int> dll;
    int size = 0;
    int cap;

public:
    MyCircularQueue(int k) {
        cap = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        dll.push_back(value); // Push to the back (tail)
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        dll.pop_front();      // Remove from the front (head)
        size--;               // Decrement size count
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return dll.front();   // First inserted element
    }

    int Rear() {
        if (isEmpty()) return -1;
        return dll.back();    // Most recently inserted element
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};