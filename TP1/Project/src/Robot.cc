#include "../include/Robot.hpp"
#include "PlanetMap.hpp"
#include <cstddef>
#include <ostream>
#include <sstream>
#include <string>

Robot::Robot(PlanetMap *m, int r)
    : activated(false), logEmpty(true), robot(r), pMap(m), aliens(0),
      recursos(0) {
  this->position[0] = 0;
  this->position[1] = 0;
}

bool Robot::isActivated() const { return this->activated; }

bool Robot::isLogEmpty() const { return this->logEmpty; }

int Robot::getPosX() const { return this->position[0]; }

int Robot::getPosY() const { return this->position[1]; }

int Robot::getRobot() const { return this->robot; }

int Robot::getAliens() const { return this->aliens; }

int Robot::getRecursos() const { return this->recursos; }

void Robot::setRecursos(int r) { this->recursos = r; }

void Robot::setAliens(int a) { this->aliens = a; }

void Robot::activate() { this->activated = true; }

std::string Robot::removeFromHistory() { return this->history.remove(); }

void Robot::writeToHistory(std::string s) { this->history.insert(s); }

void Robot::move(int a, int b) {
  if (this->pMap == nullptr) {
    ;
  } else if (a < this->pMap->getRows() && b < this->pMap->getCols() &&
             this->pMap->get(a, b) != 'O') {
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
  }
}

void Robot::cleanHistory() {
  if (!this->history.isEmpty())
    this->history.clean();
  else
    throw std::string("Nothing to clean. Empty history");
}

void Robot::receiveOrder(std::string com, int xx, int yy) {
  if (com[0] == '*') {
    com.erase(0, 1);
    this->starOrders.insert(CommandOrder(com, this->robot, xx, yy));
  } else if (com == "MOVER") {
    this->commandOrders.insert(CommandOrder(com, this->robot, xx, yy));
  } else if (com == "COLETAR" || com == "ELIMINAR") {
    this->commandOrders.insert(CommandOrder(com, this->robot));
  } else if (com == "EXECUTAR") {
    this->execute();
  }
}

void Robot::colect() {
  if (this->pMap->get(this->getPosX(), this->getPosY()) == 'R') {
    this->recursos++;
    this->pMap->changeToDot(this->getPosX(), this->getPosY());
    std::string s = "ROBO " + std::to_string(this->robot) +
                    ": RECURSOS COLETADOS EM (" +
                    std::to_string(this->getPosX()) + "," +
                    std::to_string(this->getPosY()) + ")";
    this->writeToHistory(s);
  } else {
    std::string s = "ROBO " + std::to_string(this->robot) +
                    ": IMPOSSIVEL COLETAR RECURSOS EM (" +
                    std::to_string(this->getPosX()) + "," +
                    std::to_string(this->getPosY()) + ")";
    this->writeToHistory(s);
  }
}

void Robot::eliminate() {
  if (this->pMap->get(this->getPosX(), this->getPosY()) == 'H') {
    this->aliens++;
    this->pMap->changeToDot(this->getPosX(), this->getPosY());
    std::string s = "ROBO " + std::to_string(this->robot) +
                    ": ALIEN ELIMINADO EM (" + std::to_string(this->getPosX()) +
                    "," + std::to_string(this->getPosY()) + ")";
    this->writeToHistory(s);
  } else {
    std::string s = "ROBO " + std::to_string(this->robot) +
                    ": IMPOSSIVEL ELIMINAR ALIEN EM (" +
                    std::to_string(this->getPosX()) + "," +
                    std::to_string(this->getPosY()) + ")";
    this->writeToHistory(s);
  }
}

void Robot::orderManager(CommandOrder c) {
  if (c.getOrder() == "MOVER") {
    this->move(c.getX(), c.getY());
  } else if (c.getOrder() == "COLETAR") {
    this->colect();
  } else if (c.getOrder() == "ELIMINAR") {
    this->eliminate();
  }
}

void Robot::execute() {
  if (this->isActivated()) {
    if (!this->starOrders.isEmpty()) {
      while (!this->starOrders.isEmpty()) {
        CommandOrder c = starOrders.dequeue();
        this->orderManager(c);
      }
    }
    if (!this->commandOrders.isEmpty()) {
      while (!this->commandOrders.isEmpty()) {
        CommandOrder c = commandOrders.dequeue();
        this->orderManager(c);
      }
    }
  }
}
