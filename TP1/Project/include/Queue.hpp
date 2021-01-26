#ifndef Q_H
#define Q_H

#include "Order.hpp"
#include <string>

class Queue {

private:
  int size;
  Order *front;
  Order *back;

public:
  Queue();
  ~Queue();

  void insert(Order x);
  Order *dequeue();
  void clean();

  // getters
  int getSize() const;
  bool isEmpty() const;
  Order getFront() const;
  Order getBack() const;
};

#endif