#include "../include/PlanetMap.hpp"
#include <fstream>
#include <iostream>

PlanetMap::PlanetMap() : nRows(-1), nCols(-1), m(nullptr){};

PlanetMap::PlanetMap(std::string name) {
  std::fstream myFile(name);
  int fRows = 0, fCols = 0;
  myFile >> fRows >> fCols;
  this->nRows = fRows;
  this->nCols = fCols;
  this->m = new char *[fRows];

  for (int i = 0; i < fRows; ++i) {
    this->m[i] = new char[fCols];
    for (int j = 0; j < fCols; ++j) {
      myFile >> this->m[i][j];
    }
  }
  myFile.close();
}

PlanetMap::~PlanetMap() {
  if (this->getRows() >= 0 && this->getCols() >= 0) {
    for (int i = 0; i < this->getRows(); ++i)
      delete[] this->m[i];
    delete[] this->m;
  }
}

bool PlanetMap::validatePos(int row, int column) const {
  return this->getRows() > row && this->getCols() > column;
}

void PlanetMap::changeToDot(int row, int column) {
  if (this->validatePos(row, column)) {
    if (row != 0 or column != 0)
      this->m[row][column] = '.';
  }
}

char PlanetMap::get(int a, int b) const {
  if (this->validatePos(a, b) && this->m != nullptr)
    return this->m[a][b];
  else
    return -1;
}

int PlanetMap::getRows() const { return this->nRows; }

int PlanetMap::getCols() const { return this->nCols; }
