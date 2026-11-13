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
    ull t = read_ull();
    for (size_t i = 0; i < t; ++i) {
        ull xy[2];
        read_ull_run(xy, 2, ' ');
        ull y = xy[0], x = xy[1];

        ull m = y > x ? y : x;

        ull hx, hy;
        if (m % 2 != 0) {
            hx = m * m;
            hy = (m - 1) * (m - 1) + 1;
        } else {
            hx = (m - 1) * (m - 1) + 1;
            hy = m * m;
        }

        ull ans;
        if (y <= x) {
            if (m % 2 != 0) ans = hx - (y - 1);
            else            ans = hx + (y - 1);
        } else {
            if (m % 2 != 0) ans = hy + (x - 1);
            else            ans = hy - (x - 1);
        }

        printf("%llu\n", ans);
    }
    return 0;
}
