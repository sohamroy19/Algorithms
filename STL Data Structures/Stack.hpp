#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <class T>
class Stack {
private:
    T *arr;
    int capacity;
    int top;

public:
    Stack();
    Stack(int initialCapacity);
    ~Stack();

    void reserve(int newCapacity);
    void push(T t);
    T pop();
    T peek();

    bool empty();
    bool full();
    int maxCapacity();
    int size();
};

template <class T>
Stack<T>::Stack() : capacity(0), top(-1) {}

template <class T>
Stack<T>::Stack(int initialCapacity)
    : capacity(initialCapacity), top(initialCapacity - 1) {
    arr = new T[capacity];
}

template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <class T>
void Stack<T>::reserve(int newCapacity) {
    T *tempArr = new T[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    capacity = newCapacity;
}

template <class T>
void Stack<T>::push(T t) {
    if (capacity == 0) {
        arr = new T[1];
        capacity = 1;
    } else if (full()) {
        reserve(capacity * 2);
    }

    arr[++top] = t;
}

template <class T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Cannot pop from an empty stack.");
    }
    return arr[top--];
}

template <class T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::out_of_range("Cannot peek into an empty stack.");
    }
    return arr[top];
}

template <class T>
inline bool Stack<T>::empty() { return top == -1; }

template <class T>
inline bool Stack<T>::full() { return top == capacity - 1; }

template <class T>
inline int Stack<T>::maxCapacity() { return capacity; }

template <class T>
inline int Stack<T>::size() { return top + 1; }

#endif /* STACK_HPP */