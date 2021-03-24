#ifndef BST_H
#define BST_H

#include "alphabet.hpp"
#include <sstream>
#include <string>

template <class T>
class Node {
    char item;
    int key;

public:
    Node<T> *left;
    Node<T> *right;
    Node(char letter);
    void setLeft(Node<T> *n) { this->left = n; }
    void setRight(Node<T> *n) { this->right = n; }
    void setItem(T i);
    T getItem() const { return this->item; }
    int getKey() const { return this->key; }
};

template <class T>
class BinarySearchTree {
    Node<T> *root;

    void deleteRecursive(Node<T> *r);
    void recursiveInsert(Node<T> *n, Node<T> *r);

public:
    BinarySearchTree() : root(nullptr){};
    ~BinarySearchTree();
    void insert(T n); // this.recursiveInsert(n, this.root);
    T search(int num);
};

/**** DEFINITIONS ****/

template <class T>
Node<T>::Node(char letter) : item(letter), left(nullptr), right(nullptr) {
    this->key = alphabetMap[letter];
}

template <class T>
void Node<T>::setItem(T i) {
    this->item = i;
    this->key = alphabetMap[i];
}

template <class T>
void BinarySearchTree<T>::deleteRecursive(Node<T> *r) {
    if (r != nullptr) {
        if (r->left != nullptr) {
            deleteRecursive(r->left);
        }
        if (r->right != nullptr) {
            deleteRecursive(r->right);
        }
        delete r;
    }
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (this->root) {
        this->deleteRecursive(this->root->left);
        this->deleteRecursive(this->root->right);
        delete this->root;
    }
}

template <class T>
void BinarySearchTree<T>::recursiveInsert(Node<T> *n, Node<T> *r) {
    if (n->getKey() < r->getKey()) {
        if (r->left)
            this->recursiveInsert(n, r->left);
        else
            r->setLeft(n);
    } else {
        if (r->right)
            this->recursiveInsert(n, r->right);
        else
            r->setRight(n);
    }
}

template <class T>
void BinarySearchTree<T>::insert(T n) {
    if (this->root) {
        Node<T> *newNode = new Node<T>(n);
        this->recursiveInsert(newNode, this->root);
    } else {
        this->root = new Node<T>(n);
    }
}

template <class T>
T BinarySearchTree<T>::search(int n) {
    if (n < 0)
        return this->root->getItem();

    std::ostringstream os;
    os << n;
    std::string digits = os.str();

    Node<T> *currentNode = this->root;

    for (auto &i : digits) {
        int temp = i - '0';
        if (temp % 2 == 0) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    if (currentNode == nullptr)
        return ' ';
    return currentNode->getItem();
}

#endif