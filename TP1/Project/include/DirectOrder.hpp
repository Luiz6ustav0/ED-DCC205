#ifndef DIRECT_H
#define DIRECT_H

#include "Order.hpp"
#include <string>

class DirectOrder : public Order {

private:
  DirectOrder *next;

public:
  DirectOrder(std::string order, int bot);

  void setNext(DirectOrder *i);
  DirectOrder *getNext();
};

#endif