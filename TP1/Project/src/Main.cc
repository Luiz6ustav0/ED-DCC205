#include "../include/Test.h"

int main(int argc, char* argv[]) {
    Test* pTest = new Test();
    pTest->TestQueue();
    pTest->Print();
    return 0;
}