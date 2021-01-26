#include "../include/Queue.hpp"
#include "../include/Command.hpp"

Queue::Queue() : size(0), front(nullptr), back(nullptr) {}

Queue::~Queue() {}

void Queue::insert(Command i) {
    if (this->isEmpty()) {
        this->front = new Command(i);
        this->back = this->front;
        this->size++;
    } else {

    }
};


Command Queue::dequeue() {
    return Command("Test");
};


void Queue::clean() {
    // while (this->front)
};

bool Queue::isEmpty() const {
    if (this->size > 0) return true;
    return false;
}

// getters
Command* Queue::getFront() const { return this->front; };

Command* Queue::getBack() const { return this->back; };

int Queue::getSize() const { return this->size; };
