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
    for(size_t i=0; i < t; ++i) {
        ull* xy = malloc(2 * sizeof *xy);
        read_ull_run(xy, 2, ' ');

        ull hx=0, hy=0;
        if(xy[0] % 2 != 0) {
            hx = xy[0]*xy[0];
            hy = hx - 2*xy[0] + 2;
        } else {
            hx = (xy[0]-1)*(xy[0]-1)+1;
            hy = 3*(hx-1 -2*(xy[0]-1)+2)+1;
        }

        // ugh...
        if(xy[0] == 1) {
            if(xy[1] % 2 != 0) {
                hx = xy[1]*xy[1];
                hy = hx -2*xy[1]+2;
            } else {   
                hx = (xy[1]-1)*(xy[1]-1)+1;
                hy = 3*(hx-1 -2*(xy[1]-1)+2)+1;
            }
        }

        ull ans=0;
        if(xy[0] == xy[1] || xy[0] > xy[1]) {
            ans=hx-xy[1]+1;
        } else {
            ans=hy-xy[0]+1;
        }

        printf("%llu\n", ans);
        free(xy);
    }
    return 0;
}
