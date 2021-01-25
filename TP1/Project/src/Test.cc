#include "../include/Test.h"
#include "../include/QueueArrangement.hpp"
#include <iostream>
#include <ostream>

Test::Test() : successful(0), failure(0) {}

void Test::Print() {
    std::cout << "Successful tests: " << this->successful << std::endl
              << "Failed tests: " << this->failure << std::endl;
}

bool Test::assertInt(int a, int b) {
    return a == b;
}

void Test::TestQueue() {
    QueueArrangement q;
    if (assertInt(q.getSize(), 0)) successful++;
    else failure++;
    if (assertInt(q.getFront(), q.getBack())) successful++;
    else failure++;
}
