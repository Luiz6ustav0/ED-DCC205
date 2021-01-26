#include "../include/DirectOrder.hpp"


DirectOrder::DirectOrder(std::string order, int bot)
    : Command(order, bot), next(nullptr) {};


void DirectOrder::setNext(DirectOrder* c) {
    this->next = c;
}

DirectOrder* DirectOrder::getNext() { return this->next; };

// std::string DirectOrder::getOrder() const { return this->command; }
// int DirectOrder::getRobot() const { return this->robot; };
