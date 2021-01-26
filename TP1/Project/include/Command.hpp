#ifndef COMMAND_H
#define COMMAND_H

#include <string>
        
class Command {

    private:
        std::string command;
        Command* next;

    public:
        Command(std::string order) : command(order) {};

        void setNext(Command& a);
        std::string getOrder() const;
        int getRobot() const;
};

#endif