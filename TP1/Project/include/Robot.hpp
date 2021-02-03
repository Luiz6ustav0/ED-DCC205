#include "CommandOrder.hpp"
#include "DirectOrder.hpp"
#include "Queue.hpp"
#include "PlanetMap.hpp"

class Robot {
  bool activated;
  bool logEmpty;
  int position[2];
  PlanetMap *pMap;

public:
  Robot(PlanetMap *m=nullptr);

  Queue<DirectOrder> directOrders;
  Queue<CommandOrder> commandOrders;

  // getters
  bool isLogEmpty() const;
  bool isActivated() const;
  int getPosX() const;
  int getPosY() const;

  // setters/utils
  void activate();
  void move(int x, int y);
  void setMap(PlanetMap *m);
};