#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

template <class T>
class Queue {
private:
    T *arr;
    int capacity;
    int front, rear;

public:
    Queue() : capacity(0), front(0), rear(-1) {}

    Queue(int size) : capacity(size), front(0), rear(-1) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T t) {
        if (capacity == 0) {
            capacity = 1;
            arr = new T[capacity];
        } else if (isFull()) {
            T *tempArr = new T[capacity * 2];

            for (int i = front; i <= rear; ++i) {
                tempArr[i - front] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = tempArr;
        }

        arr[++rear] = t;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot dequeue from an empty queue.");
        } else if (size() == 1) {
            int tempIndex = front;
            front = 0;
            rear = -1;
            return arr[tempIndex];
        } else {
            return arr[front++];
        }
    }

    T peek() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty queue.");
        }
        return arr[front];
    }

    int size() {
        return rear - front + 1;
    }

    int maxCapacity() {
        return capacity;
    }

    bool isEmpty() {
        return size() == 0;
    }

    bool isFull() {
        return rear == capacity - 1;
    }
};

#endif /* QUEUE_HPP */