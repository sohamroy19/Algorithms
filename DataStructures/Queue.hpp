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
    Queue();
    Queue(int initialCapacity);
    ~Queue();

    void reserve(int newCapacity);
    void enqueue(T t);
    T dequeue();
    T peek();

    bool isEmpty();
    bool isFull();
    int maxCapacity();
    int size();
};

template <class T>
Queue<T>::Queue() : capacity(0), front(0), rear(-1) {}

template <class T>
Queue<T>::Queue(int initialCapacity) : capacity(initialCapacity), front(0), rear(-1) {
    arr = new T[capacity];
}

template <class T>
~Queue<T>::Queue() {
    delete[] arr;
}

template <class T>
void Queue<T>::reserve(int newCapacity) {
    T *tempArr = new T[newCapacity];

    for (int i = front; i <= rear; ++i) {
        tempArr[i - front] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    capacity = newCapacity;
    rear -= front;
    front = 0;
}

template <class T>
void Queue<T>::enqueue(T t) {
    if (maxCapacity() == 0) {
        reserve(1);
    } else if (isFull()) {
        reserve(capacity * 2);
    }

    arr[++rear] = t;
}

template <class T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot dequeue from an empty queue.");
    } else if (size() == 1) {
        int oldFront = front;
        front = 0;
        rear = -1;
        return arr[oldFront];
    } else {
        return arr[front++];
    }
}

template <class T>
T Queue<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot peek into an empty queue.");
    }
    return arr[front];
}

template <class T>
inline bool Queue<T>::isEmpty() { return size() == 0; }

template <class T>
inline bool Queue<T>::isFull() { return rear == capacity - 1; }

template <class T>
inline int Queue<T>::maxCapacity() { return capacity; }

template <class T>
inline int Queue<T>::size() { return rear - front + 1; }

#endif /* QUEUE_HPP */