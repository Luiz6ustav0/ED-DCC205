#include "PlanetMap.hpp"
#include "Robot.hpp"

class Base {
  PlanetMap *m;
  Robot r[50];
  int aliens, recursos;

  public:
    Base(std::string mapName);
    ~Base();
    PlanetMap* getMapPointer();
    void relatorioFinal() const;
    void sendOrder(std::string c, int robot, int x=-1, int y=-1);
};