struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {
    private:
        IntNode *Head;
        IntNode *Tail;
    public:
        IntList();
        ~IntList();
        void display() const;
        void push_front(int value);
        void pop_front();
        bool empty() const; 
};