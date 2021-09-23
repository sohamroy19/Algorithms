#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <stdexcept>

template <class T>
class Deque {
private:
    T *arr;
    int capacity;
    int front, rear;

public:
    Deque() : capacity(0), front(0), rear(-1) {}

    Deque(int size) : capacity(size), front(0), rear(-1) {
        arr = new T[capacity];
    }

    ~Deque() {
        delete[] arr;
    }

    void pushFront(T t) {
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

        front = (front + capacity - 1) % capacity;
        arr[front] = t;
    }

    void pushBack(T t) {
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

    T popFront() {
        int oldFront = front;
        if (isEmpty()) {
            throw std::out_of_range("Cannot dequeue from an empty deque.");
        } else if (size() == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return arr[oldFront];
    }

    T popBack() {
        int oldRear = rear;
        if (isEmpty()) {
            throw std::out_of_range("Cannot dequeue from an empty deque.");
        } else if (size() == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear + capacity - 1) % capacity;
        }
        return arr[oldRear];
    }

    T peekFront() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty deque.");
        }
        return arr[front];
    }

    T peekBack() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty deque.");
        }
        return arr[rear];
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

#endif /* DEQUE_HPP */