#include "../include/QueueArrangement.hpp"


QueueArrangement::QueueArrangement() : size(0), front(0), back(0) {}


void QueueArrangement::insert(std::string i) {
    
};


std::string QueueArrangement::dequeue() {
    return 0;
};


void QueueArrangement::clean() {
    
};

// getters
int QueueArrangement::getFront() const { return this->front; };

int QueueArrangement::getBack() const { return this->back; };

int QueueArrangement::getSize() const { return this->size; };
