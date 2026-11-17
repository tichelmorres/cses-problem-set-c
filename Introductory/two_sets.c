#include <stdio.h>

typedef unsigned long long ull;

ull read_ull(void) {
    int c; ull n=0;
    while((c=getchar()) != EOF && (c < '0' || c > '9'))
    ;
    while(c>='0' && c<='9') {
        n=n*10 + (ull)(c - '0');
        c=getchar();
    }
    if(c!=EOF) ungetc(c, stdin);
    return n;
}

#define MAX_SIZE 1000001

int main(void) {
    ull n = read_ull();
    ull t = n*(n+1)/2;

    if(t%2!=0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");

    t = t/2;
    ull s1[MAX_SIZE]; ull s2[MAX_SIZE];
    int c1=0, c2=0;
    while(n > 0) {
        if (n <= t) { s1[c1++] = n; t -= n; }
        else        { s2[c2++] = n; }
        --n;
    }

    printf("%d\n", c1);
    for(int i=0; i<c1; ++i) printf("%llu ", s1[i]);
    printf("\n");
    printf("%d\n", c2);
    for(int i=0; i<c2; ++i) printf("%llu ", s2[i]);
    return 0;
}
