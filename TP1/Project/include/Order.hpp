#ifndef ORDER_H
#define ORDER_H

#include <string>
        
class Order {

    private:
        std::string command;
        int robot;
        Order* next;

    public:
        Order(std::string order, int bot) : command(order), robot(bot) {};

        void setNext(Order& a);
        Order* getNext() { return this->next; };
        std::string getOrder() const { return this->command; };
        int getRobot() const { return this->robot; };
        
};

#endif