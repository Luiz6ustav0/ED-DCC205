#ifndef Q_H
#define Q_H

#include "DirectOrder.hpp"
#include "Order.hpp"
#include <string>

///* Classe Celula *///

template <class T> class Celula {
  T item;
  Celula<T> *next;

public:
  Celula() : next(nullptr) {}
  Celula<T> *getNext() const { return this->next; }
  void setNext(Celula<T> *n) { this->next = n; }
  void setItem(T i) { this->item = i; }
  T getItem() const { return this->item; }
};

///* Classe Fila *///

template <class T> class Queue {

private:
  int size;
  Celula<T> *front;
  Celula<T> *back;

public:
  Queue();
  ~Queue();

  // Operations
  void insert(T x);
  T dequeue();
  void cheatInsert(T x);
  void clear();

  // Getters
  int getSize() const;
  bool isEmpty() const;
  Celula<T> *getFront() const;
};

template <class T> Queue<T>::Queue() : size(0), front(nullptr), back(nullptr) {}

template <class T> Queue<T>::~Queue() {
  while (front != nullptr) {
    Celula<T> *temp = this->front;
    this->front = this->front->getNext();
    delete temp;
  }
};

///* Operations *///

template <class T> void Queue<T>::insert(T x) {
  Celula<T> *temp = new Celula<T>;
  temp->setItem(x);
  // temp->getNext() = nullptr;
  if (this->back == nullptr) {
    this->back = temp;
    this->front = temp;
  } else {
    this->back->setNext(temp);
    this->back = temp;
  }
  size++;
}

template <class T> T Queue<T>::dequeue() {
  if (this->front != nullptr) {
    T order = this->getFront()->getItem();

    Celula<T> *temp = this->front;
    this->front = this->front->getNext();
    delete temp;
    size--;
    if (this->getSize() == 0) {
      this->back = this->front = nullptr;
    }
    return order;
  }
  throw "Fila vazia";
};

template <class T> void Queue<T>::cheatInsert(T x) {
  Celula<T> *temp = new Celula<T>;
  temp->setItem(x);
  if (this->front == nullptr) {
    this->front = temp;
    this->back = temp;
  } else {
    temp->setNext(this->front);
    this->front = temp;
  }
  size++;
}

template <class T> void Queue<T>::clear() {
  while (front != nullptr) {
    Celula<T> *temp = this->front;
    this->front = this->front->getNext();
    delete temp;
    size--;
  }
  this->back = this->front = nullptr;
}

///* Getters *///

template <class T> bool Queue<T>::isEmpty() const {
  return this->size <= 0 ? true : false;
};

template <class T> int Queue<T>::getSize() const { return this->size; };

template <class T> Celula<T> *Queue<T>::getFront() const { return this->front; }

#endif