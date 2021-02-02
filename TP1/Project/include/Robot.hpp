#include "CommandOrder.hpp"
#include "DirectOrder.hpp"
#include "Queue.hpp"

class Robot {
  bool activated;
  bool logEmpty;
  int position[2];

public:
  Robot();

  Queue<DirectOrder> directOrders;
  Queue<CommandOrder> commandOrders;

  bool isLogEmpty() const;
  bool isActivated() const;
  int getPosX() const;
  int getPosY() const;
};