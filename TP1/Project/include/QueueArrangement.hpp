#include "Queue.hpp"

#define MAXSIZE 100

template<class T>
class QueueArrangement : Queue <T> {

    private:
        int front;
        int back;
        T itens[MAXSIZE];

    public:
        QueueArrangement();
        // int getFront() const;
        // int getBack() const;

        void insert(T x);
        T dequeue();
        void clean();

};