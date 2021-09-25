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
    void insertAt(T t, int index);

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
    std::unique_ptr<NodeLL> newHead = std::make_unique<NodeLL>(t);

    if (head) newHead->next = std::move(head);

    head = std::move(newHead);
    ++currentSize;
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
void LinkedList<T>::insertAt(T t, int index) {
    std::unique_ptr<NodeLL> newHead = std::make_unique<NodeLL>(t);
    std::unique_ptr<NodeLL> *nextNode = &head;

    for (int i = 0; i < index; ++i) {
        if (*nextNode) nextNode = &(*nextNode->next);
    }

    if (*nextNode) newHead->next = std::move(*nextNode);

    *nextNode = std::move(newHead);
    ++currentSize;
}

template <class T>
inline bool LinkedList<T>::isEmpty() { return size() == 0; }

template <class T>
inline int LinkedList<T>::size() { return currentSize; }

#endif /* LINKED_LIST_HPP */