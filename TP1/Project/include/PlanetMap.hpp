#ifndef MAP_H
#define MAP_H
#include <string>

class PlanetMap {
  char **m;
  int nRows;
  int nCols;
  bool validatePos(int x, int y) const;

public:
  PlanetMap();
  PlanetMap(std::string s);
  ~PlanetMap();

  void changeToDot(int x, int y);

  // basic getters
  int getRows() const;
  int getCols() const;
  char get(int row, int col) const;
};

#endif