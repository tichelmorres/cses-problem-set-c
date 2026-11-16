#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull read_ull(void) {
    int c;
    ull n = 0;

    while ((c = getchar()) != EOF && (c < '0' || c > '9'))
        ;
    while (c >= '0' && c <= '9') {
        n = n * 10 + (ull)(c - '0');
        c = getchar();
    }
    if (c != EOF)
        ungetc(c, stdin);
    return n;
}

int main(void) {
    ull n = read_ull();

    for(size_t k = 1; k <= n; ++k) {
        ull k2=k*k;
        ull ans=k2*(k2-1)/2;
        if(k > 2) {
            ans -= 4*(k-1)*(k-2);
        }
        printf("%llu\n", ans);
    }

    return 0;
}
