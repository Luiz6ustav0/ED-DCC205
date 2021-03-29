#ifndef BST_H
#define BST_H

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
    Node<T> *recursiveInsert(Node<T> *n, Node<T> *r);

public:
    BinarySearchTree() : root(nullptr){};
    ~BinarySearchTree();
    void insert(T n); // this.recursiveInsert(n, this.root);
    T search(int num);
    std::string pathOf(char c);
    Node<T> *getRoot() { return this->root; };
};

/**** DEFINITIONS ****/

template <class T>
Node<T>::Node(char letter) : item(letter), left(nullptr), right(nullptr) {
    this->key = int(letter);
}

template <class T>
void Node<T>::setItem(T i) {
    this->item = i;
    this->key = int(i);
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
Node<T> *BinarySearchTree<T>::recursiveInsert(Node<T> *n, Node<T> *r) {
    if (r == nullptr)
        return n;
    if (n->getKey() < r->getKey()) {
        r->setLeft(this->recursiveInsert(n, r->left));
    } else if (n->getKey() > r->getKey()) {
        r->setRight(this->recursiveInsert(n, r->right));
    }
    return r;
}

template <class T>
void BinarySearchTree<T>::insert(T n) {
    if (this->root == nullptr)
        this->root = new Node<T>(n);

    else {
        Node<T> *newNode = new Node<T>(n);
        this->recursiveInsert(newNode, this->root);
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

    if (digits.size() >= 1) {
        for (auto &i : digits) {
            int temp = i - '0';
            if (temp % 2 == 0 || temp == 0) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }
    }
    return currentNode->getItem();
}

template <class T>
std::string BinarySearchTree<T>::pathOf(char c) {
    std::stringstream path;
    int searchKey = int(c);

    Node<T> *currentNode = this->root;

    while (currentNode != nullptr) {
        if (searchKey == currentNode->getKey())
            break;
        if (searchKey < currentNode->getKey()) {
            path << 'L';
            currentNode = currentNode->left;
        } else {
            path << 'R';
            currentNode = currentNode->right;
        }
    }
    return path.str();
}

#endif