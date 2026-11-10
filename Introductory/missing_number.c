#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// long long inputs can contain at max 22 chars.
// (-9,223,372,036,854,775,807) + "\n" + '\0'.

// this problem requires only positive integers,
// which means long long could be unsigned,
// but this rule still applies.
// (18,446,744,073,709,551,615) + "\n" + '\0'.

#define BUF_SIZE 22
#define ull unsigned long long

typedef struct {
    const char* str;
    size_t len;
} sview_t;

sview_t sv(const char* cstr) {
    return (sview_t) {
        .str = cstr,
        .len = strlen(cstr)
    };
}

void sv_chop_left(sview_t* sv, size_t n) {
    if(n >= sv->len) return;
    sv->len -= n;
    sv->str += n;
}

void sv_chop_right(sview_t* sv, size_t n) {
    if(n >= sv->len) return;
    sv->len -= n;
}

sview_t sv_chop_by_delim(sview_t* sv, char d) {
    size_t i = 0;
    while (i < sv->len && sv->str[i] != d) i++;

    sview_t token = { .str = sv->str, .len = i };

    if (i < sv->len) {
        sv->str += i + 1;
        sv->len -= i + 1;
    } else {
        sv->str += sv->len;
        sv->len = 0;
    }
    return token;
}

void sv_trim_left(sview_t* sv) {
    while (sv->len > 0 && isspace((unsigned char)sv->str[0])) {
        sv->str++; sv->len--;
    }
}

void sv_trim_right(sview_t* sv) {
    while (sv->len > 0 && isspace((unsigned char)sv->str[sv->len-1]))
        sv->len--;
}

void sv_trim(sview_t* sv) {
    sv_trim_left(sv);
    sv_trim_right(sv);
}

char* sv_parse_input(sview_t sv) {
    sv_trim(&sv);

    char* buf = malloc(sv.len + 2);
    if (!buf) return NULL;

    size_t n = 0;
    while (sv.len > 0) {
        sview_t tok = sv_chop_by_delim(&sv, ' ');
        if (tok.len == 0) continue;

        memcpy(buf + n, tok.str, tok.len);
        n += tok.len;
        buf[n++] = '\0';
    }
    buf[n] = '\0';

    return buf; // needs to be freed
}

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
    char sequence[BUF_SIZE * n];
    if (fgets(sequence, sizeof sequence, stdin) == NULL) {
        fprintf(stderr, "ERROR: Could not read from stdin\n");
        exit(1);
    }
    sequence[strcspn(sequence, "\n")] = '\0';

    sview_t s = sv(sequence);

    char* nums = sv_parse_input(s);
    if (!nums) return 1;

    ull sum = 0;
    for (char* p = nums; *p != '\0'; p += strlen(p) + 1) {
        char* end;
        ull a = strtoull(p, &end, 10);
        sum += a;
    }

    printf("%llu", n*(n+1)/2-sum);

    free(nums);
    return 0;
}
