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
    CircularQueue();
    CircularQueue(int initialCapacity);
    ~CircularQueue();

    void reserve(int newCapacity);
    void enqueue(T t);
    T dequeue();
    T peek();

    bool isEmpty();
    bool isFull();
    int size();
    int maxCapacity();
};

template <class T>
CircularQueue<T>::CircularQueue() : capacity(0), front(0), rear(-1) {}

template <class T>
CircularQueue<T>::CircularQueue(int initialCapacity)
    : capacity(initialCapacity), front(0), rear(-1) {
    arr = new T[capacity];
}

template <class T>
CircularQueue<T>::~CircularQueue() {
    delete[] arr;
}

template <class T>
void CircularQueue<T>::reserve(int newCapacity) {
    T *tempArr = new T[newCapacity];

    if (rear != -1 && rear < front) rear += n;
    for (int i = front; i <= rear; ++i) {
        tempArr[i - front] = arr[i % capacity];
    }

    delete[] arr;
    arr = tempArr;
    capacity = newCapacity;
    rear -= front;
    front = 0;
}

template <class T>
void CircularQueue<T>::enqueue(T t) {
    if (maxCapacity() == 0) {
        reserve(1);
    } else if (isFull()) {
        reserve(capacity * 2);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = t;
}

template <class T>
T CircularQueue<T>::dequeue() {
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

template <class T>
T CircularQueue<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot peek into an empty queue.");
    }
    return arr[front];
}

template <class T>
inline bool CircularQueue<T>::isEmpty() { return rear == -1; }

template <class T>
inline bool CircularQueue<T>::isFull() { return front == (rear + 1) % capacity; }

template <class T>
inline int CircularQueue<T>::size() {
    if (isEmpty()) return 0;
    return (rear >= front) ? rear - front + 1 : rear + n - front + 1;
}

template <class T>
inline int CircularQueue<T>::maxCapacity() { return capacity; }

#endif /* CIRCULAR_QUEUE_HPP */