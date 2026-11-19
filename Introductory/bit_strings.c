#include <stdio.h>

typedef unsigned long long ull;

#define MOD 1000000007ULL

int main(void) {
    ull n=0;
    if(scanf("%llu", &n) != 1) return 1;

    ull ans=1;
    for(ull i = 0; i < n; ++i) ans=(ans * 2)%MOD;

    printf("%llu\n", ans);
    return 0;
}
