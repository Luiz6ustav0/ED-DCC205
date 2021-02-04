#include "CommandOrder.hpp"
#include "DirectOrder.hpp"
#include "List.hpp"
#include "PlanetMap.hpp"
#include "Queue.hpp"

class Robot {
  int robot;
  bool activated;
  bool logEmpty;
  int position[2];
  PlanetMap *pMap;
  List<std::string> history;
  void writeToHistory(std::string s);

public:
  Robot(PlanetMap *m = nullptr, int robo = -1);

  Queue<DirectOrder> directOrders;
  Queue<CommandOrder> commandOrders;

  // getters
  bool isLogEmpty() const;
  bool isActivated() const;
  int getPosX() const;
  int getPosY() const;
  int getRobot() const;
  std::string removeFromHistory();

  // setters/utils
  void activate();
  void move(int x, int y);
  void setMap(PlanetMap *m);
  void printHistory();
  void cleanHistory();
};