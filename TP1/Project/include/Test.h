#ifndef TEST_H
#define TEST_H

#include <stdio.h>

class Test 
{   private:
        int successful;
        int failure;
    public:
        Test();
        void TestQueue();
        // ~Test();
        void Print();
        bool assertInt(int a, int b);
};

#endif