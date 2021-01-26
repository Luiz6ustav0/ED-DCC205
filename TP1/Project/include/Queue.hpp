#ifndef Q_H
#define Q_H

#include <string>
#include "Command.hpp"
        
class Queue {

    private:
        int size;
        Command* front;
        Command* back;

    public:
        Queue();
        ~Queue();

        void insert(Command x);
        Command dequeue();
        void clean();

        // getters
        int getSize() const;
        bool isEmpty() const;
        Command* getFront() const;
        Command* getBack() const;

};

#endif