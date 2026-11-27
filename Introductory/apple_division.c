#include <stdio.h>

#define INF 1000000000000000000LL
#define ABS(x) ((x) >= 0 ? (x) : -1*(x))
#define MIN(x, y) ((x) <= (y) ? (x) : (y))

typedef long long ll;

int main(void) {
    int n = 0;
    if(scanf("%d", &n) != 1) return 1;

    ll ps[n];
    ll T=0;
    for(int i=0; i < n; ++i) {
        ll p=0;
        if(scanf(" %lld", &p) != 1) return 1;
        ps[i]=p; T+=p;
    }

    ll ans=INF;
    // 2^n
    for(ll m=0; m < (1LL << n); ++m) {
        ll A=0;
        for(int j=0; j < n; ++j) {
            if(m & (1LL << j))
                A+=ps[j];
        }
        ll d = ABS(A - (T - A));
        ans = MIN(ans, d);
    }

    printf("%lld\n", ans);
    return 0;
}
