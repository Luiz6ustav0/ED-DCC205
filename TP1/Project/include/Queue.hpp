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
  Celula(T a) : item(a), next(nullptr){};
  void setNext(T a) { this->next = new Celula<T>(a); };
  Celula<T> *getNext() { return this->next; };
  T getItem() { return this->item; };
};

template <class T> class Queue {

private:
  int size;
  Celula<T> *front;
  Celula<T> *back;

public:
  Queue();
  ~Queue();

  void insert(T x);
  T dequeue();
  void clean();

  // getters
  int getSize() const;
  bool isEmpty() const;
  Celula<T> *getFront() const;
  Celula<T> *getBack() const;
};

template <class T> Queue<T>::Queue() : front(nullptr), back(nullptr), size(0){};

template <class T> Queue<T>::~Queue() {
  while (this->front != nullptr) {
    Celula<T> *temp = this->front->getNext();
    delete this->front;
    this->front = temp;
  }
};

template <class T> void Queue<T>::insert(T x) {
  if (this->front == nullptr) {
    this->front = new Celula<T>(T(x));
    this->back = this->front;
    size++;
  } else {
    this->back->setNext(x);
  }
}

template <class T> bool Queue<T>::isEmpty() const {
  return this->size <= 0 ? true : false;
};

template <class T> int Queue<T>::getSize() const { return this->size; };

template <class T> Celula<T> *Queue<T>::getFront() const { return this->front; }

template <class T> Celula<T> *Queue<T>::getBack() const { return this->back; }

#endif