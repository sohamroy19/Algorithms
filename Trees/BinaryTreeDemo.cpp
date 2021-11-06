#include "BinaryTree.hpp"

#include <iostream>

int main() {
    BinaryTree<int> tree;
    tree.root = std::make_unique<BinaryTree<int>::NodeBT>(1);
    tree.root->left = std::make_unique<BinaryTree<int>::NodeBT>(2);
    tree.root->right = std::make_unique<BinaryTree<int>::NodeBT>(3);
    tree.root->left->left = std::make_unique<BinaryTree<int>::NodeBT>(4);
    tree.root->left->right = std::make_unique<BinaryTree<int>::NodeBT>(5);
    tree.root->right->left = std::make_unique<BinaryTree<int>::NodeBT>(6);
    tree.root->right->right = std::make_unique<BinaryTree<int>::NodeBT>(7);

    for (auto &i : tree.preOrder()) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto &i : tree.inOrder()) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto &i : tree.postOrder()) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto &i : tree.traverse(BinaryTree<int>::preOrderNode)) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto &i : tree.traverse(BinaryTree<int>::inOrderNode)) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    for (auto &i : tree.traverse(BinaryTree<int>::postOrderNode)) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}