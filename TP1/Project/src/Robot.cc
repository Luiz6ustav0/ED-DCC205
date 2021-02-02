#include "Robot.hpp"

Robot::Robot() : activated(false), logEmpty(true) {
    this->position[0] = 0;
    this->position[1] = 0;
}

bool Robot::isActivated() const {
    return this->activated;
}

bool Robot::isLogEmpty() const {
    return this->logEmpty;
}

int Robot::getPosX() const {
    return this->position[0];
}

int Robot::getPosY() const {
    return this->position[1];
}