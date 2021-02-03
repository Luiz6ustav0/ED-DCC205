#ifndef MAP_H
#define MAP_H
#include <string>

class PlanetMap {
  char **m;
  int nRows;
  int nCols;

public:
  PlanetMap();
  PlanetMap(std::string s);
  ~PlanetMap();
  // basic getters
  int getRows() const;
  int getCols() const;
  char get(int row, int col) const;
};

#endif