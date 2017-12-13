#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int m, n, i, j;
    bool flag;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++){
        flag = true;
        for (j = 2; j <= i - 1;j++)
            if (!(flag = i % j))
                break;
        if (flag)
            printf("%d ", i);
    }
    return 0;
}