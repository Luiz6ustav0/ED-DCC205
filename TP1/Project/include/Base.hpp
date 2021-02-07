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
    // void printRetornoRobo(int a, int r) const;
    void relatorioFinal() const;
    void sendOrder(std::string c, int robot, int x=-1, int y=-1);
};