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
    Stack() : capacity(0), top(-1) {}

    Stack(int size) : capacity(size), top(size - 1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T t) {
        if (capacity == 0) {
            capacity = 1;
            arr = new T[capacity];
        } else if (isFull()) {
            T *tempArr = new T[capacity * 2];
            
            for (int i = 0; i < capacity; ++i) {
                tempArr[i] = arr[i];
            }
            
            delete[] arr;
            capacity *= 2;
            arr = tempArr;
        }

        arr[++top] = t;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot pop from an empty stack.");
        }
        return arr[top--];
    }

    T peek() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty stack.");
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

#endif /* STACK_HPP */