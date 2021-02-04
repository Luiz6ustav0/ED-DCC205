#include "../include/Robot.hpp"
#include "PlanetMap.hpp"
#include <cstddef>
#include <ostream>
#include <sstream>
#include <string>

Robot::Robot(PlanetMap *m, int r)
    : activated(false), logEmpty(true), robot(r), pMap(m) {
  this->position[0] = 0;
  this->position[1] = 0;
}

bool Robot::isActivated() const { return this->activated; }

bool Robot::isLogEmpty() const { return this->logEmpty; }

int Robot::getPosX() const { return this->position[0]; }

int Robot::getPosY() const { return this->position[1]; }

int Robot::getRobot() const { return this->robot; }

void Robot::activate() { this->activated = true; }

std::string Robot::removeFromHistory() { return this->history.remove(); }

void Robot::writeToHistory(std::string s) { this->history.insert(s); }

void Robot::move(int a, int b) {
  if (this->pMap == nullptr) {
    ;
  } else if (a < this->pMap->getRows() && b < this->pMap->getCols()) {
    this->position[0] = a;
    this->position[1] = b;
    std::string str = "ROBO " + std::to_string(this->getRobot()) +
                      ": MOVEU PARA (" + std::to_string(a) + "," +
                      std::to_string(b) + ")";
    this->writeToHistory(str);
  } else {
    std::string str = "ROBO " + std::to_string(this->getRobot()) +
                      ": IMPOSSIVEL MOVER PARA (" + std::to_string(a) + "," +
                      std::to_string(b) + ")";
    this->writeToHistory(str);
  }
}

void Robot::printHistory() {
  if (!this->history.isEmpty()) {
    this->history.printList();
  } else
    throw std::string("Nothing to print. Empty history");
}

void Robot::cleanHistory() {
  if (!this->history.isEmpty())
    this->history.clean();
  else
    throw std::string("Nothing to clean. Empty history");
}
