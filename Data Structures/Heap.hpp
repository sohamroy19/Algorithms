#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept>

template <class T>
class Heap {
private:
    T *arr;
    int currentSize, capacity;

public:
    Heap();
    Heap(T *arr, int size);
    ~Heap();

    void heapify();
    void remove(int index);

    void reserve(int newCapacity);
    void push(T t);
    T pop();
    T peek();

    bool isEmpty();
    bool isFull();
    int maxCapacity();
    int size();
};

template <class T>
Heap<T>::Heap() : currentSize(0), capacity(0) {}

template <class T>
Heap<T>::Heap(T *arr, int size) : currentSize(0), capacity(size) {
    arr = new T[size];
}

template <class T>
Heap<T>::~Heap() {
    delete[] arr;
}

template <class T>
void Heap<T>::reserve(int newCapacity) {
    T *tempArr = new T[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    capacity = newCapacity;
}

template <class T>
inline bool Heap<T>::isEmpty() { return size() == 0; }

template <class T>
inline bool Heap<T>::isFull() { return size() == maxCapacity(); }

template <class T>
inline int Heap<T>::maxCapacity() { return capacity; }

template <class T>
inline int Heap<T>::size() { return currentSize; }

#endif /* HEAP_HPP */