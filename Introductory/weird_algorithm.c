#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// long long inputs can contain at max 22 chars.
// (-9,223,372,036,854,775,807) + "\n" + '\0'.

// this problem requires only positive integers,
// which means long long could be unsigned,
// but this rule still applies.
// (18,446,744,073,709,551,615) + "\n" + '\0'.

#define BUF_SIZE 22
#define ull unsigned long long

ull get_ull_input(void) {
    char input[BUF_SIZE];
    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "ERROR: Could not read from stdin\n");
        exit(1);
    }
    input[strcspn(input, "\n")] = '\0';

    char *end;
    ull n = strtoull(input, &end, 10);
    if (end == input || *end != '\0' || input[0] == '-') {
        fprintf(stderr, "ERROR: Invalid input\n");
        exit(1);
    }
    return n;
}

int main(void) {
    ull n = get_ull_input();
    printf("%llu ", n);

    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        // (n > (ULLONG_MAX - 1) / 3) means an overflow
        else n = n*3 + 1;
        printf("%llu ", n);
    }

    return 0;
}
