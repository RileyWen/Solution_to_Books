#include <math.h>
#include <stdio.h>
int main(){
    long long t, n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", (long long)ceil(log(n) / log(2)));
    }
    return 0;
}