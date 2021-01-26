#include "../include/CommandOrder.hpp"
#include <string>

CommandOrder::CommandOrder(std::string order, int bot, int posX, int posY)
    : Order(order, bot), next(nullptr), x(posX), y(posY){};

CommandOrder *CommandOrder::getNext() { return this->next; };

void CommandOrder::setNext(CommandOrder *i) { this->next = i; };

// getters
int CommandOrder::getX() const { return this->x; }

int CommandOrder::getY() const { return this->y; }
