#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
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
        else{
            char return_zero[sizeof(T)];
            memset(return_zero, 0, sizeof(T));
            return *((T *)(&return_zero[0]));
        }
        
    }

    bool isempty(){
        return (this->size == 0);
    }

    void popall(){
        while (!(this->isempty()))
            this->pop();
    }

    T* gettop(){
        return &(this->top->element);
    }
};

struct _Operator{
    char _operator = 0;
    int priority = 0;
    bool left_combine = true;
};

int SignToIndex(char sign){
    switch (sign){
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        case '(':
            return 5;
        case ')':
            return 6;
        }
}

void init(_Operator *opt){
    opt[0]._operator = '+';
    opt[1]._operator = '-';
    opt[0].priority = opt[1].priority = 0;
    opt[2]._operator = '*';
    opt[3]._operator = '/';
    opt[2].priority = opt[3].priority = 1;
    opt[4]._operator = '^';
    opt[4].priority = 2;
    opt[4].left_combine = false;
    opt[5]._operator = '(';
    opt[6]._operator = ')';
    opt[5].priority = 100;
    opt[6].priority = 100;
}

double GetNum(char* expression, int& cursor){
    if (expression[cursor]<='9' && expression[cursor]>='0'){
        double interger = 0.0f, frac = 0.0f;
        int cnt = 0;
        bool isfrac = false;
        while (true)
        {
            //printf("%d", 1);
            if (expression[cursor] <= '9' && expression[cursor] >= '0')
            {
                if (!isfrac){
                    interger = interger * 10 + double(expression[cursor++] - '0');
                }
                else{
                    cnt++;
                    double frac_tmp = double(expression[cursor++] - '0');
                    for (int i = 1; i <= cnt; i++)
                        frac_tmp /= 10;
                    frac += frac_tmp;
                }
            }
            else if (expression[cursor]=='.'){
                isfrac = true;
                cursor++;
            }
            else
                break;
        }
        double result = interger + frac;
        return result;
    }
    exit(-1);
}

void compute(Stack<double>& num,_Operator op){
    double num2 = num.pop();
    double num1 = num.pop();
    switch (op._operator){
        case '+':
            num.push(num1 + num2);
            break;
        case '-':
            num.push(num1 - num2);
            break;
        case '*':
            num.push(num1 * num2);
            break;
        case '/':
            num.push(num1 / num2);
            break;
        case '^':
            num.push(pow(num1, num2));
            break;
        default:
            exit(-1);
        }
}

int main()
{
    _Operator Operator[7], tmp;
    char expression[1000] = {};
    int cursor = 0, element_cnt = 0;
    Stack<_Operator> operators;
    Stack<double> num;
    bool isSign[1000] = {};

    init(Operator);
    operators.gettop()->priority = -2;

    gets(expression);
    while (expression[cursor])
    {
        
        //printf("%d", 1);
        if (expression[cursor]<='9' && expression[cursor]>='0'){
            //printf("%.0lf ",GetNum(expression, cursor));
            num.push(GetNum(expression, cursor));
            isSign[++element_cnt] = false;
        }
        else if(expression[cursor]){
            //printf("%c %c\n", Operator[SignToIndex(expression[cursor])]._operator, operators.gettop()->_operator);
            
            //printf("%d %d", Operator[SignToIndex(expression[cursor])].priority, operators.gettop()->priority);
            //getchar();
            _Operator current_operator = Operator[SignToIndex(expression[cursor])];
            if (current_operator._operator == '('){
                operators.push(current_operator);
                cursor++;
                continue;
            }
            if (current_operator._operator == ')'){
                cursor++;           //pop ')'
                while (!operators.isempty() && (operators.gettop())->_operator != '(')
                {
                    //printf("%c ", (operators.pop())._operator);
                    compute(num, operators.pop());
                }
                operators.pop();    //pop '('
                continue;
            }
            if ((current_operator.priority > (operators.gettop())->priority)
                 || (current_operator.priority == (operators.gettop())->priority && !current_operator.left_combine))
            {
                //printf("cursor:%d\n",cursor);
                operators.push(current_operator);
                cursor++;
            }
            else{
                //printf("cursor:%d\n",SignToIndex(expression[cursor]));
                    while(operators.gettop()->_operator!= '(' && operators.gettop()->priority >= current_operator.priority){
                        //printf("%d %d", operators.gettop()->priority,current.priority);
                        //getchar();
                        //printf("%c ", operators.pop()._operator);

                        compute(num, operators.pop());
                    }
                    operators.push(current_operator);
                    cursor++;
            }
            isSign[++element_cnt] = true;
        }
        else
            break;
    }
    while(!operators.isempty())
    {
        //tmp = operators.pop();
        //printf("%c ", tmp._operator);
        compute(num, operators.pop());
    }
    printf("%.0lf", num.pop());
    return 0;
}
