#include <stdio.h>
typedef struct {
    long long a;
    long long b;
    long long u;
} Com;

Com t;

Com test(long long a,long long b){
    t.a = a;
    t.b = b;
    t.u = 0;
    return t;
}

int main(){
    Com tmp = test(10, 3);
    printf("%lld\n", tmp.b);
    return 0;
}