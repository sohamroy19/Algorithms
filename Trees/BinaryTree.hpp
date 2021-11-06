#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include <queue>
#include <stdexcept>
#include <vector>

template <class T>
class BinaryTree {
public:
    class NodeBT {
    public:
        T data;
        std::unique_ptr<NodeBT> left, right;

        NodeBT(T initData) : data(initData), left(nullptr), right(nullptr) {}
    };

    int currentSize;
    std::unique_ptr<NodeBT> root;

    void preOrderNode(const NodeBT &nd, std::vector<T> &res);
    void inOrderNode(const NodeBT &nd, std::vector<T> &res);
    void postOrderNode(const NodeBT &nd, std::vector<T> &res);

    BinaryTree();
    ~BinaryTree();

    std::vector<T> preOrder();
    std::vector<T> inOrder();
    std::vector<T> postOrder();

    template <class Function>
    std::vector<T> traverse(Function traversalMethod);

    bool empty() const;
    int size() const;
};

template <class T>
BinaryTree<T>::BinaryTree() : currentSize(0), root(nullptr) {}

template <class T>
BinaryTree<T>::~BinaryTree() {
    std::queue<std::unique_ptr<NodeBT>> q;
    q.push(std::move(root));

    while (!q.empty()) {
        if (q.front()->left) q.push(std::move(q.front()->left));
        if (q.front()->right) q.push(std::move(q.front()->right));
        q.pop();
    }
}

template <class T>
template <class Function>
std::vector<T> BinaryTree<T>::traverse(Function traversalMethod) {
    std::vector<T> res;
    if (root) (this->*traversalMethod)(*root, res);

    return res;
}

template <class T>
std::vector<T> BinaryTree<T>::preOrder() {
    std::vector<T> result;
    if (root) preOrderNode(*root, result);

    return result;
}

template <class T>
std::vector<T> BinaryTree<T>::inOrder() {
    std::vector<T> result;
    if (root) inOrderNode(*root, result);

    return result;
}

template <class T>
std::vector<T> BinaryTree<T>::postOrder() {
    std::vector<T> result;
    if (root) postOrderNode(*root, result);

    return result;
}

template <class T>
void BinaryTree<T>::preOrderNode(const NodeBT &nd, std::vector<T> &res) {
        res.push_back(nd.data);
        if (nd.left) preOrderNode(*nd.left, res);
        if (nd.right) preOrderNode(*nd.right, res);
}

template <class T>
void BinaryTree<T>::inOrderNode(const NodeBT &nd, std::vector<T> &res) {
        if (nd.left) inOrderNode(*nd.left, res);
        res.push_back(nd.data);
        if (nd.right) inOrderNode(*nd.right, res);
}

template <class T>
void BinaryTree<T>::postOrderNode(const NodeBT &nd, std::vector<T> &res) {
        if (nd.left) postOrderNode(*nd.left, res);
        if (nd.right) postOrderNode(*nd.right, res);
        res.push_back(nd.data);
}

template <class T>
inline bool BinaryTree<T>::empty() const { return size() == 0; }

template <class T>
inline int BinaryTree<T>::size() const { return currentSize; }

#endif /* BINARY_TREE_HPP */