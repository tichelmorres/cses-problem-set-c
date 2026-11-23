#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
    char c;
    while((c=getchar()) != EOF && (c < 'A' || c > 'Z'))
        ;
    int d[26] = { 0 };
    char s[1000000];
    int l[26] = { 0 };
    int cnt=0;
    while(c >='A' && c <='Z') {
        int i=(int)c-65;
        d[i]+=1;
        l[i]++;
        if (l[i] == 2) {
            s[cnt] = c;
            cnt++;
            l[i] = 0;
        }
        c=getchar();
    }
    int o=0;
    char littlefella = '\0';
    for(int i=0; i < 26; ++i) {
        if(d[i] %2 !=0) {
            o++;
            // littlefella = (char)(i + 65); // also works for some reason
        }
        if(l[i]!= 0 && l[i]!=2) littlefella=(char)(i+65);
    }
    if(o > 1) printf("NO SOLUTION\n");
    else {
        int cap=0;
        if(!littlefella) {
            cap=cnt*2;
        } else {
            cap=cnt*2+1;
        }
        char ans[cap+1];
        for (int i = 0; i < cnt; ++i) {
            ans[i] = s[i];
            ans[cap - 1 - i] = s[i];
        }
        if(littlefella) ans[cap/2] = littlefella;
        ans[cap] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
