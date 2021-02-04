#ifndef LIST_H
#define LIST_H
#include <string>
template <class T> class Node {
private:
  T data;
  Node *next;

public:
  Node<T>(T d, Node *n = nullptr) : data(d), next(n){};
  void setData(T d) { this->data = d; };
  void setNext(Node<T> *n) { this->next = n; };
  T getData() const { return this->data; };
  Node *getNext() const { return this->next; };
};

template <class T> class List {
public:
  List();
  void insert(T value);
  T remove(); // pops head
  bool isEmpty();
  int getSize() const;
  ~List();
  // void printList();

private:
  Node<T> *head;
  Node<T> *last;
  int size;
  // void clearList();
};

template <class T> List<T>::List() : size(0), head(nullptr), last(nullptr) {}

template <class T> List<T>::~List() {
  if (this->head) {
    while (this->head) {
      Node<T> *current = this->head;
      this->head = this->head->getNext();
      delete current;
    }
  }
}

template <class T> void List<T>::insert(T val) {
  if (this->head) {
    Node<T> *node = new Node<T>(val, nullptr);
    this->last->setNext(node);
    this->last = node;
    this->size++;
  } else {
    this->head = new Node<T>(val);
    this->last = this->head;
    this->size++;
  }
}

template <class T> T List<T>::remove() {
  if (this->head) {
    T item = this->head->getData();
    Node<T> *temp = this->head;
    this->head = this->head->getNext();
    delete temp;
    this->size--;
    return item;
  }
  throw std::string("Can't remove element. Empty list");
}

template <class T> int List<T>::getSize() const { return this->size; }

template <class T> bool List<T>::isEmpty() {
  return this->getSize() > 0 ? false : true;
}

#endif