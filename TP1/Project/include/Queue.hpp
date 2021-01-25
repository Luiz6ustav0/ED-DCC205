template<class T>
class Queue {
    protected:
        int size;

    public:
        Queue() { this->size = 0; };

        // getters
        int getSize() const;
        bool isEmpty() const;

        // virtual
        virtual void insert(T i) = 0;
        virtual T dequeue() = 0;
        virtual void clean() = 0;
};