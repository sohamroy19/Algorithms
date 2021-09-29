#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <class T>
class LinkedList {

    class NodeLL {
    public:
        T data;
        std::unique_ptr<NodeLL> next;

        NodeLL(T initData) : data(initData), next(nullptr) {}
    };

private:
    int currentSize;
    std::unique_ptr<NodeLL> head;

public:
    LinkedList();
    ~LinkedList();

    void push(T t);
    T pop();
    T peek();

    void insert(T t, int index);
    void remove(int index);

    bool isEmpty();
    int size();
};

template <class T>
LinkedList<T>::LinkedList() : currentSize(0), head(nullptr) {}

template <class T>
LinkedList<T>::~LinkedList() {
    while (head) head = std::move(head->next);
}

template <class T>
void LinkedList<T>::push(T t) {
    insert(t, 0);
}

template <class T>
T LinkedList<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot pop from an empty linked list.");
    }

    std::unique_ptr<NodeLL> oldHead = std::move(head);
    head = std::move(oldHead->next);
    --currentSize;

    return oldHead->data;
}

template <class T>
T LinkedList<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Cannot peek into an empty linked list.");
    }

    return head->data;
}

template <class T>
void LinkedList<T>::insert(T t, int index) {
    if (index > size()) {
        throw std::out_of_range("Index out of range.");
    }

    std::unique_ptr<NodeLL> newNode = std::make_unique<NodeLL>(t);
    std::unique_ptr<NodeLL> *atNode = &head;

    for (int i = 0; i < index; ++i) {
        atNode = &((*atNode)->next);
    }

    if (*atNode) newNode->next = std::move(*atNode);

    *atNode = std::move(newNode);
    ++currentSize;
}

template <class T>
void LinkedList<T>::remove(int index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range.");
    }

    std::unique_ptr<NodeLL> *atNode = &head;

    for (int i = 0; i < index; ++i) {
        atNode = &((*atNode)->next);
    }

    if (*atNode) {
        std::unique_ptr<NodeLL> tempNode = std::move(*atNode);
        *atNode = std::move(tempNode->next);
        --currentSize;
    }
}

template <class T>
inline bool LinkedList<T>::isEmpty() { return size() == 0; }

template <class T>
inline int LinkedList<T>::size() { return currentSize; }

#endif /* LINKED_LIST_HPP */