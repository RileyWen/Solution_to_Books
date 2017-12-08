#include <stdio.h>
#include <stdlib.h>
int main(){
    char tmp[1000];
    int cur=0;
    while ((*(tmp+cur) = getchar()) != '\n')
        cur++;
    while (printf("%c",*(tmp+cur)),cur--){}
    return 0;
}