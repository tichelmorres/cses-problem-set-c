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
    size_t n = (size_t)read_ull();
    if(n == 1) { printf("1"); return 0; }
    if(n == 2 || n == 3) { printf("NO SOLUTION"); return 0; }
    ull p[n];

    // odd
    if(n % 2 != 0) {
        ull i=n-1, j=n/2-1;
        ull c=2;
        while(i >= n/2) {
            p[j]=c--; p[i]=c;
            c += 3; i--; j--;
        }
    } else { // even
        ull i=n/2, j=0;
        ull c=1;
        while(i < n) {
            p[i]=c++; p[j]=c++;
            i++; j++;
        }
    }

    for(ull i=0; i < n; ++i) {
        if(i == n-1) {
            printf("%llu", p[i]);
            break;
        }
        printf("%llu ", p[i]);
    }

    return 0;
}
