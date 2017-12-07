#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;
bool once_underflow = false;

void stack_overflow(){
    printf("Stack overflow");
    exit(-1);
}

void stack_underflow(){
    once_underflow = true;
}

void make_empty(){
    top = 0;
}

bool is_empty(void){
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;
}

void push(char i){
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

char pop(void){
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}
int main(){
    char tmp;
    while ((tmp=getchar())!='\n'){
        if (tmp=='('||tmp=='{'){
            push(tmp);
            continue;
        }
        if (tmp=='}'){
            if (pop()!='{'){
                printf("Parenteses/braces are not nested properly");
                return 0;
            }
        }
        if (tmp==')'){
            if (pop()!='('){
                printf("Parenteses/braces are not nested properly");
                return 0;
            }
        }
    }
    if (!is_empty()||once_underflow)
        printf("Parenteses/braces are not nested properly");
    else
        printf("Parenteses/braces are nested properly");
    return 0;
}
