#ifndef LIST_H
#define LIST_H

template <class T> class Node {
private:
  T data;
  Node *next;

public:
  Node<T>(T d, Node *n) : data(d), next(n){};
  void setData(T d) { this->data = d; };
  void setNext(Node<T> *n) { this->next = n; };
  T getData() const { return this->data; };
  Node *getNext() const { return this->next; };
};

template <class T> class List {
public:
  List();
  void insert(T value);
  // Node<T> remove(); // pops head
  bool isEmpty();
  int getSize() const;
  ~List();
  // void printList();

private:
  Node<T> *head;
  Node<T> *last;
  int size;
  // bool isHeadPresent() const;
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

template <class T> int List<T>::getSize() const {
  return this->size;
}

template <class T> bool List<T>::isEmpty() {
  return this->getSize() > 0 ? false : true ;
}

#endif