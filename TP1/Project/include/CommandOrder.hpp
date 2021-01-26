#ifndef COMMAND_H
#define COMMAND_H

#include "Order.hpp"
#include <string>

class CommandOrder : public Order {

private:
  CommandOrder *next;
  int x, y;

public:
  CommandOrder(std::string order, int bot, int posX = -1, int posY = -1);

  void setNext(CommandOrder *i);
  CommandOrder *getNext();
  int getX() const;
  int getY() const;
};

#endif