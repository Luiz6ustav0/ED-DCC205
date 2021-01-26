#include "../include/DirectOrder.hpp"

DirectOrder::DirectOrder(std::string order, int bot)
    : Order(order, bot), next(nullptr){};

void DirectOrder::setNext(DirectOrder *c) { this->next = c; }

DirectOrder *DirectOrder::getNext() { return this->next; };
