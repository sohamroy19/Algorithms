#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <class T>
class DoublyLinkedList {

    class NodeDLL {
    public:
        T data;
        std::unique_ptr<NodeDLL> next;
        NodeDLL *prev;

        NodeDLL(T initData, NodeDLL *owner)
            : data(initData), next(nullptr), prev(owner) {}
    };

private:
    int currentSize;
    std::unique_ptr<NodeDLL> head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push(T t);
    T pop();
    T peek() const;

    void insert(T t, int index);
    void remove(int index);

    bool empty() const;
    int size() const;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : currentSize(0), head(nullptr) {}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) head = std::move(head->next);
}

template <class T>
void DoublyLinkedList<T>::push(T t) {
    insert(t, 0);
}

template <class T>
T DoublyLinkedList<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Cannot pop from an empty linked list.");
    }

    std::unique_ptr<NodeDLL> oldHead = std::move(head);
    head = std::move(oldHead->next);
    head->prev = nullptr;
    --currentSize;

    return oldHead->data;
}

template <class T>
T DoublyLinkedList<T>::peek() const {
    if (empty()) {
        throw std::out_of_range("Cannot peek into an empty linked list.");
    }

    return head->data;
}

template <class T>
void DoublyLinkedList<T>::insert(T t, int index) {
    if (index > size()) {
        throw std::out_of_range("Index out of range.");
    }

    std::unique_ptr<NodeDLL> *atNode = &head;

    for (int i = 0; i < index; ++i) {
        atNode = &((*atNode)->next);
    }

    std::unique_ptr<NodeDLL> newNode = std::make_unique<NodeDLL>(t, nullptr);

    if (*atNode) {
        newNode->prev = (*atNode)->prev;
        (*atNode)->prev = newNode.get();
        newNode->next = std::move(*atNode);
    }

    *atNode = std::move(newNode);
    ++currentSize;
}

template <class T>
void DoublyLinkedList<T>::remove(int index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range.");
    }

    std::unique_ptr<NodeDLL> *atNode = &head;

    for (int i = 0; i < index; ++i) {
        atNode = &((*atNode)->next);
    }

    if (*atNode) {
        std::unique_ptr<NodeDLL> tempNode = std::move(*atNode);
        *atNode = std::move(tempNode->next);
        (*atNode)->prev = tempNode->prev;
        --currentSize;
    }
}

template <class T>
inline bool DoublyLinkedList<T>::empty() const { return size() == 0; }

template <class T>
inline int DoublyLinkedList<T>::size() const { return currentSize; }

#endif /* DOUBLY_LINKED_LIST_HPP */