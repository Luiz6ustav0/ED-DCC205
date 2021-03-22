#ifndef BST_H
#define BST_H

#include "alphabet.hpp"
#include <string>

template <class T>
class Node {
    char item;
    int key;
    Node<T> *left;
    Node<T> *right;

public:
    Node(char letter);
    Node<T> *getLeft() const { return this->left; }
    Node<T> *getRight() const { return this->right; }
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
    BinarySearchTree(T r = NULL);
    ~BinarySearchTree();
    void insert(T n); // this.recursiveInsert(n, this.root);
    std::string search(int num);
};

/**** DEFINITIONS ****/

template <class T>
Node<T>::Node(char letter) : left(nullptr), right(nullptr), item(letter) {
    this->key = alphabetMap[letter];
}

template <class T>
void Node<T>::setItem(T i) {
    this->item = i;
    this->key = alphabetMap[i];
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T r) {
    if (r) {
        this->root = new Node(r);
    } else {
        this->root = nullptr;
    }
}

template <class T>
void BinarySearchTree<T>::deleteRecursive(Node<T> *r) {
    if (r->getLeft()) {
        deleteRecursive(r->getLeft());
    }
    if (r->getRight()) {
        deleteRecursive(r->getRight());
    }
    delete r;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (this->root) {
        this->deleteRecursive(this->root->getLeft());
        this->deleteRecursive(this->root->getRight());
        delete this->root;
    }
}

template <class T>
void BinarySearchTree<T>::recursiveInsert(Node<T> *n, Node<T> *r) {
    if (n->getKey() < r->getKey()) {
        if (r->getLeft())
            this->recursiveInsert(n, r->getLeft());
        else
            r->setLeft(n);
    } else {
        if (r->getRight())
            this->recursiveInsert(n, r->getRight());
        else
            r->setRight(n);
    }
}

template <class T>
void BinarySearchTree<T>::insert(T n) {
    if (this->root) {
        Node<T> *newNode = new Node(n);
        this->recursiveInsert(newNode; this->root);
    } else {
        this->root = new Node(r);
    }
}

template <class T>
std::string BinarySearchTree<T>::search(int n) {
}

#endif