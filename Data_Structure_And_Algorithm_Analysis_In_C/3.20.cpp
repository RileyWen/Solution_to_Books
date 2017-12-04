#include <iostream>
using namespace std;

template <typename T> class Stack_Node{
    public: 
    T element;
    Stack_Node *Next;

    
    //constructor with no parameter
    Stack_Node()
    {
        this->Next = NULL;
    }

    //constructor that initialize *Next to next node
    Stack_Node(Stack_Node *Next){
        this->Next = Next;
    }

};

template <typename T> class Stack{
    private:
    unsigned int size;
    Stack_Node<T> *top;
    
    public:
    
    ~Stack(){
        this->popall();
        delete this->top;
    }
    
    Stack(){
        this->top = new Stack_Node<T>;
        this->size = 0;
    }

    

    void push(T element){
        Stack_Node<T> *tmp = this->top;
        this->top = new Stack_Node<T>;
        this->top->element = element;
        this->top->Next = tmp;
        this->size++;
    }

    T pop(){
        if (!this->isempty()){
            T element_tmp = this->top->element;
            Stack_Node<T>* tmp=this->top->Next;
            delete this->top;
            this->top = tmp;
            this->size--;
            return element_tmp;
        }
        else
            return {};
    }

    bool isempty(){
        return (this->top->Next == NULL);
    }

    void popall(){
        while (!(this->isempty()))
            this->pop();
    }
};

struct _Operator{
    char _operator;
    unsigned int priority;
};

void init(_Operator *opt){
    opt[0]._operator = '+';
    opt[1]._operator = '-';
    opt[0].priority = opt[1].priority = 0;
    opt[2]._operator = '*';
    opt[3]._operator = '/';
    opt[0].priority = opt[1].priority = 1;
    opt[4]._operator = '^';
    opt[4].priority = 2;
}

int main(){
    _Operator Operator[5];
    init(Operator);
    Stack<char> operators;
    Stack<double> num;
    
    return 0;
}