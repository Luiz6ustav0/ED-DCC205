#include "../include/Queue.hpp"


Queue::Queue() : size(0), front(0), back(0) {}

Queue::~Queue() {}

void Queue::insert(std::string i) {
    
};


std::string Queue::dequeue() {
    return 0;
};


void Queue::clean() {
    
};

// getters
int Queue::getFront() const { return this->front; };

int Queue::getBack() const { return this->back; };

int Queue::getSize() const { return this->size; };
