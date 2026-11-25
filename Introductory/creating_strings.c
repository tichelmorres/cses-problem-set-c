#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 8
#define MAXP 40320  // 8!

static char perms[MAXP][MAXN + 1];
static int count = 0;

static int cmp_char(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

void solve(const char *s, int n, char *aux, int depth, int *used) {
    if (depth == n) {
        aux[n] = '\0';
        strcpy(perms[count++], aux);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        used[i] = 1;
        aux[depth] = s[i];
        solve(s, n, aux, depth + 1, used);
        used[i] = 0;
    }
}

int main(void) {
    char s[MAXN + 1];
    if (scanf("%8s", s) != 1) return 0;

    int n = (int)strlen(s);
    qsort(s, n, sizeof(char), cmp_char);

    char aux[MAXN + 1];
    int used[MAXN] = {0};
    solve(s, n, aux, 0, used);

    printf("%d\n", count);
    for (int i = 0; i < count; i++)
        printf("%s\n", perms[i]);
    return 0;
}
