#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept>

template <class T>
class Heap {
private:
    T *arr;
    int currentSize, capacity;

    void heapifySubtree(int index);

public:
    Heap();
    Heap(T *arr, int size);
    ~Heap();

    void heapify();
    void remove(int index);

    void reserve(int newCapacity);
    void push(T t);
    T pop();
    T peek() const;

    bool empty() const;
    bool full() const;
    int maxCapacity() const;
    int size() const;
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
void Heap<T>::heapify() {
    for (int i = currentSize / 2 - 1; i >= 0; --i) {
        heapifySubtree(i);
    }
}

template <class T>
void Heap<T>::heapifySubtree(int index) {
    int l = 2 * index + 1, r = 2 * index + 2;
    int target = index;

    if (arr[l] > arr[target]) target = l;
    if (r < currentSize && arr[r] > arr[target]) target = r;

    if (target != index) {
        using std::swap; // enable ADL
        swap(arr[index], arr[target]);
        heapifySubtree(target);
    }
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
void Heap<T>::push(T t) {
    if (maxCapacity() == 0) {
        reserve(1);
    } else if (full()) {
        reserve(capacity * 2);
    }

    arr[currentSize++];
    heapify();
}

template <class T>
T Heap<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Cannot pop from an empty heap.");
    }

    using std::swap; // enable ADL
    swap(arr[0], arr[--currentSize]);
    heapify();

    return arr[currentSize];
}

template <class T>
T Heap<T>::peek() const {
    if (empty()) {
        throw std::out_of_range("Cannot peek into an empty heap.");
    }

    return arr[0];
}

template <class T>
inline bool Heap<T>::empty() const { return size() == 0; }

template <class T>
inline bool Heap<T>::full() const { return size() == maxCapacity(); }

template <class T>
inline int Heap<T>::maxCapacity() const { return capacity; }

template <class T>
inline int Heap<T>::size() const { return currentSize; }

#endif /* HEAP_HPP */