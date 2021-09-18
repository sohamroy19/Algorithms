#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack {
private:
    T *internalArray;
    int capacity;
    int size;

public:
    Stack() : capacity(0), size(0) {}

    Stack(int initialSize) : capacity(initialSize), size(initialSize) {
        internalArray = new T[capacity];
    }

    ~Stack() {
        delete[] internalArray;
    }
};

#endif /* STACK_HPP */