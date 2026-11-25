#include <stdio.h>

void hanoi(int n, int start, int end) {
    if(n==1) {
        printf("%d %d\n", start, end);
    } else {
        int other = 6 - (start+end);
        hanoi(n-1, start, other);
        printf("%d %d\n", start, end);
        hanoi(n-1, other, end);
    }
}

int main(void) {
    int n=0;
    if(scanf("%d", &n) != 1) return 1;

    int start=1, end=3;
    // Sierpinski Pyramid's side is given by 2^n,
    // subtract one because we don't care about the
    // first case
    printf("%d\n", (1<<n)-1);
    hanoi(n, start, end);

    return 0;
}
