#ifndef Q_H
#define Q_H

#include "Order.hpp"
#include <string>

template <class T> class Queue {

private:
  int size;
  T *front;
  T *back;

public:
  Queue();
  ~Queue();

  void insert(T x);
  T *dequeue();
  void clean();

  // getters
  int getSize() const;
  bool isEmpty() const;
  T* getFront() const;
  T* getBack() const;
};

template <class T> Queue<T>::Queue() : front(nullptr), back(nullptr), size(0){};

template <class T> Queue<T>::~Queue() {
  if (this->front != nullptr) delete front;
  if (this->back != nullptr) delete back;
};

template <class T> bool Queue<T>::isEmpty() const { return this->size <= 0 ? true : false; };

template <class T> int Queue<T>::getSize() const { return this->size; };

template <class T> T* Queue<T>::getFront() const { return this->front; }

template <class T> T* Queue<T>::getBack() const { return this->back; }

#endif