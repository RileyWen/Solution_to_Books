#include <stdio.h>
#include <stdlib.h>
int main(){
    char tmp[1000];
    int cnt=0;
    while ((tmp[cnt]=getchar())!='\n')
        cnt++;
    while (printf("%c",tmp[cnt]),cnt--){}
    return 0;
}