#ifndef COMMAND_H
#define COMMAND_H

#include <string>
        
class Command {

    private:
        std::string command;

    public:
        Command(std::string order) : command(order) {};

        virtual std::string getOrder() const = 0;
};

#endif