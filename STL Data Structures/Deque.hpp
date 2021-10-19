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
    Deque();
    Deque(int initialCapacity);
    ~Deque();

    void reserve(int newCapacity);
    void pushBack(T t);
    void pushFront(T t);
    T popBack();
    T popFront();
    T peekBack();
    T peekFront();

    void enqueue(T t);
    T dequeue();

    bool empty();
    bool full();
    int maxCapacity();
    int size();
};

template <class T>
Deque<T>::Deque() : capacity(0), front(0), rear(-1) {}

template <class T>
Deque<T>::Deque(int initialCapacity) : capacity(initialCapacity), front(0), rear(-1) {
    arr = new T[capacity];
}

template <class T>
Deque<T>::~Deque() {
    delete[] arr;
}

template <class T>
void Deque<T>::reserve(int newCapacity) {
    T *tempArr = new T[newCapacity];

    if (!empty() && rear < front) rear += n;
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
void Deque<T>::pushBack(T t) {
    if (maxCapacity() == 0) {
        reserve(1);
    } else if (full()) {
        reserve(capacity * 2);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = t;
}

template <class T>
void Deque<T>::pushFront(T t) {
    if (maxCapacity() == 0) {
        reserve(1);
    } else if (full()) {
        reserve(capacity * 2);
    }

    front = (front + capacity - 1) % capacity;
    arr[front] = t;
}

template <class T>
T Deque<T>::popBack() {
    int oldRear = rear;

    if (empty()) {
        throw std::out_of_range("Cannot dequeue from an empty deque.");
    } else if (size() == 1) {
        front = 0;
        rear = -1;
    } else {
        rear = (rear + capacity - 1) % capacity;
    }

    return arr[oldRear];
}

template <class T>
T Deque<T>::popFront() {
    int oldFront = front;

    if (empty()) {
        throw std::out_of_range("Cannot dequeue from an empty deque.");
    } else if (size() == 1) {
        front = 0;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }

    return arr[oldFront];
}

template <class T>
T Deque<T>::peekBack() {
    if (empty()) {
        throw std::out_of_range("Cannot peek into an empty deque.");
    }
    return arr[rear];
}

template <class T>
T Deque<T>::peekFront() {
    if (empty()) {
        throw std::out_of_range("Cannot peek into an empty deque.");
    }
    return arr[front];
}

template <class T>
inline void Deque<T>::enqueue(T t) { pushBack(t); }

template <class T>
inline T Deque<T>::dequeue() { return popFront(); }

template <class T>
inline bool Deque<T>::empty() { return rear == -1; }

template <class T>
inline bool Deque<T>::full() { return front == (rear + 1) % capacity; }

template <class T>
inline int Deque<T>::maxCapacity() { return capacity; }

template <class T>
inline int Deque<T>::size() {
    return empty() ? 0 : (rear >= front) ? rear - front + 1
                                           : rear + n - front + 1;
}

#endif /* DEQUE_HPP */