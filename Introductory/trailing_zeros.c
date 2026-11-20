#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
    ull n = 0;
    if(scanf("%llu", &n) !=1) return 1;

    ull ans=0;
    while(n>0) {
        ans += n/5;
        n/=5;
    }

    printf("%llu", ans);    
    return 0;
}
