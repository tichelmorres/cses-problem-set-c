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

size_t read_ull_run(ull *out, size_t max, char sep) {
    int c, in_num = 0;
    size_t count = 0;
    ull cur = 0;

    while (count < max) {
        c = getchar();
        if (c >= '0' && c <= '9') {
            cur = cur * 10 + (ull)(c - '0');
            in_num = 1;
            continue;
        }
        if (in_num) {
            out[count++] = cur;
            cur = 0;
            in_num = 0;
        }
        if (c == EOF)
            break;
        if ((c == '\n' || c == '\r') && count > 0)
            break;
        if (c == sep)
            continue;
    }
    return count;
}

int main(void) {
    size_t n = (size_t)read_ull();
    ull *a = malloc(n * sizeof *a);
    read_ull_run(a, n, ' ');

    ull m=0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            m += a[i-1] - a[i];
            a[i]=a[i-1];
        }
    }

    printf("%llu", m);

    free(a);
    return 0;
}
