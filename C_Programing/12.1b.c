#include <stdio.h>
#include <stdlib.h>
int main(){
    char tmp[1000];
    char *cur = tmp;
    while ((*cur = getchar()) != '\n')
        cur++;
    while (printf("%c",*cur),cur--!=tmp){}
    return 0;
}