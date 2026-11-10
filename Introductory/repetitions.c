#include <stdio.h>
#include <string.h>

#define BUF_SIZE 2000000
#define ull unsigned long long

int modrc(int x) {
    if(x >= 0) return x;
    return -x;
}

int max(int x, int y) {
    return (x + y + modrc(x - y))/2;
}

int main(void) {
    char s[BUF_SIZE];
    fgets(s, sizeof s, stdin);
    s[strcspn(s, "\n")] = '\0';

    int ans=0, c=0;
    char l='A';
    for(size_t i = 0; i < strlen(s); ++i) {
        char d=s[i];
        if(d==l) {
            ++c;
            ans=max(c, ans);
        } else {
            l=d;
            c=1;
        }
    }

    printf("%d", ans);

    return 0;
}
