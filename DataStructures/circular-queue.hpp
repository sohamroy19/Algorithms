#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <stdexcept>

template <class T>
class CircularQueue {
private:
    T *arr;
    int capacity;
    int front, rear;

public:
    CircularQueue() : capacity(0), front(0), rear(-1) {}

    CircularQueue(int size) : capacity(size), front(0), rear(-1) {
        arr = new T[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(T t) {
        if (capacity == 0) {
            capacity = 1;
            arr = new T[capacity];
            front = rear = 0;
        } else if (isFull()) {
            T *tempArr = new T[capacity * 2];

            for (int i = front; i <= rear; ++i) {
                tempArr[i - front] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = tempArr;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = t;
    }

    T dequeue() {
        int oldFront = front;
        if (isEmpty()) {
            throw std::out_of_range("Cannot dequeue from an empty queue.");
        } else if (size() == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return arr[oldFront];
    }

    T peek() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty queue.");
        }
        return arr[front];
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear >= front) ? rear - front + 1 : rear + n - front + 1;
    }

    int maxCapacity() {
        return capacity;
    }

    bool isEmpty() {
        return rear == -1;
    }

    bool isFull() {
        return front == (rear + 1) % capacity;
    }
};

#endif /* CIRCULAR_QUEUE_HPP */