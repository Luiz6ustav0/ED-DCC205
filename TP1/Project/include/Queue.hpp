#ifndef Q_H
#define Q_H

#include "DirectOrder.hpp"
#include "Order.hpp"
#include <string>

/* Classe Celula */

template <class T> class Celula {
  T item;
  Celula<T> *next;

public:
  Celula() : next(nullptr) {}
  Celula<T>* getNext() const { return this->next; }
  void setNext(Celula<T> *n) { this->next = n; }
  void setItem(T i) { this->item = i; }
  T getItem() const { return this->item; }
};

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

template <class T> bool Queue<T>::isEmpty() const {
  return this->size == 0 ? true : false;
};

template <class T> int Queue<T>::getSize() const { return this->size; };

template <class T> Celula<T> *Queue<T>::getFront() const { return this->front; }

#endif