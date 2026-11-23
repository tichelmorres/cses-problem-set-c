
#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
    ull t, a, b;

    if (scanf("%llu", &t) != 1)
        return 1;

    while (t--) {
        if (scanf("%llu %llu", &a, &b) != 2)
            return 1;

        if ((a + b) % 3 == 0 &&
            (a <= 2 * b && b <= 2 * a)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
