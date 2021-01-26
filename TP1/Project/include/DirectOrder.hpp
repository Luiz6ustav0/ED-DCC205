#ifndef DIRECT_H
#define DIRECT_H

#include <string>
#include "Command.hpp"
        
class DirectOrder : Command {

    private:
        std::string command;
        Command* next;
        int robot;

    public:
        DirectOrder(std::string order, int bot);

        std::string getOrder() const;
        int getRobot() const;
        void setNext(Command* i);
};

#endif