#include <stdio.h>

void print_bin(unsigned int val, int columns) {
    for (int i = columns - 1; i >= 0; i--) {
        putchar((val & (1U << i)) ? '1' : '0');
    }
}

int main(void) {
    int n=0;
    if(scanf("%d", &n)!=1) return 1;

    int ans=0;
    for(int i=0; i < (1<<n); ++i) {
        ans=i ^ (i>>1);
        print_bin(ans, n);
        printf("\n");
    }

    return 0;
}
