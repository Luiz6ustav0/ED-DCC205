#ifndef DIRECT_H
#define DIRECT_H

#include <string>
#include "Command.hpp"
        
class DirectOrder : Command {

    private:
        std::string command;
        int robot, x, y;

    public:
        DirectOrder(std::string order, int bot, int posX=0, int posY=0);

        std::string getOrder() const;
        int getRobot() const;
        int getPosX() const;
        int getPosY() const;
};

#endif