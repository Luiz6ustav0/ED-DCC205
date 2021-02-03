#include "Robot.hpp"
#include "PlanetMap.hpp"
#include <cstddef>

Robot::Robot(PlanetMap *m) : activated(false), logEmpty(true), pMap(m) {
  this->position[0] = 0;
  this->position[1] = 0;
}

bool Robot::isActivated() const { return this->activated; }

bool Robot::isLogEmpty() const { return this->logEmpty; }

int Robot::getPosX() const { return this->position[0]; }

int Robot::getPosY() const { return this->position[1]; }

void Robot::activate() { this->activated = true; }

void Robot::move(int a, int b) {
  if (this->pMap == nullptr)
    ;
  else if (a < this->pMap->getRows() && b < this->pMap->getCols()) {
    this->position[0] = a;
    this->position[1] = b;
  }
}