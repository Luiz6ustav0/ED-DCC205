#include "../include/DirectOrder.hpp"


DirectOrder::DirectOrder(std::string order, int bot, int posX, int posY)
    : Command(order), robot(bot), x(posX), y(posY) {};


std::string DirectOrder::getOrder() const { return this->command; }
int DirectOrder::getPosX() const { return this->x; };
int DirectOrder::getPosY() const { return this->y; };
int DirectOrder::getRobot() const { return this->robot; };
