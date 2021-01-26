#include "../include/Queue.hpp"
#include "../include/Order.hpp"

Queue::Queue() : size(0), front(nullptr), back(nullptr) {}

Queue::~Queue() {}

void Queue::insert(Order i) {
    if (this->isEmpty()) {
        this->front = new Order(i);
        this->back = this->front;
        this->size++;
    } else {

    }
};


Order* Queue::dequeue() {
    return this->front;
};


void Queue::clean() {
    // while (this->front)
};

bool Queue::isEmpty() const {
    if (this->size > 0) return true;
    return false;
}

// getters
Order Queue::getFront() const { return *(this->front); };

Order Queue::getBack() const { return *(this->back); };

int Queue::getSize() const { return this->size; };
