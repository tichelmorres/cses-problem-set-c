// I thought Hamming distance
//   meant 1 unit apart in binary lol
#include <stdio.h>

int powrc(int x, int y) {
    while((y)--) x*=x;
    return x;
}

void print_bin(unsigned int val, int columns) {
    for (int i = columns - 1; i >= 0; i--) {
        putchar((val & (1U << i)) ? '1' : '0');
    }
}

int main(void) {
    int n=0;
    if(scanf("%d", &n)!=1) return 1;

    int ans=0;
    for(int i=0; i<powrc(2, n-1); ++i) {
        print_bin(ans, n);
        printf("\n");
        ans+=1;
    }
}
