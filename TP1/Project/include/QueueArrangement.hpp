#ifndef Q_ARR
#define Q_ARR

#include <string>
#define MAXSIZE 100

        
class QueueArrangement {

    private:
        int size;
        int front;
        int back;
        std::string itens[MAXSIZE];

    public:
        QueueArrangement();

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