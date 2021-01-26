#ifndef Q_H
#define Q_H

#include <string>
        
class Queue {

    private:
        int size;
        int front;
        int back;

    public:
        Queue();
        ~Queue();

        void insert(std::string x);
        std::string dequeue();
        void clean();

        // getters
        int getSize() const;
        bool isEmpty() const;
        int getFront() const;
        int getBack() const;

};

#endif