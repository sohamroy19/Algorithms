#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept>

template <class T>
class Heap {
private:
    T *arr;
    int currentSize;

public:
    Heap();
    Heap(T *arr, int size);
    ~Heap();

    void heapify();
    void insert(T t);
    void remove(int index);

    T peek();
    void pop();

    bool isEmpty();
    bool isFull();
    int maxCapacity();
    int size();
};

#endif /* HEAP_HPP */