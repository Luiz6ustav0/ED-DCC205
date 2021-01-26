#include "../include/DirectOrder.hpp"


DirectOrder::DirectOrder(std::string order, int bot)
    : Command(order), robot(bot), next(nullptr) {};


void DirectOrder::setNext(Command* c) {
    this->next = c;
}

std::string DirectOrder::getOrder() const { return this->command; }
int DirectOrder::getRobot() const { return this->robot; };
