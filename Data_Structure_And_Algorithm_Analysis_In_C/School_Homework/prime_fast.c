#include <time.h>
#include <stdio.h>
#include <math.h>
int main(){
    clock_t start, end;
    double time_used;
    int n,sqrtn,cnt=0,i,j;
    int flag;
    scanf("%d", &n);

    start = clock();
    for (i = 2; i <= n;i++){
        flag = 1;
        sqrtn = sqrt(i);
        for (j = 2; j <= sqrtn; j++)
            if (i%j==0){
                flag = 0;
                break;
            }
        if  (flag)
            cnt++;
    }

    end = clock();
    time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("cnt: %d\n", cnt);
    printf("time used: %lf\n", time_used);
    return 0;
}