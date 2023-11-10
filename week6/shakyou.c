#include <stdio.h>
#include <string.h>

typedef struct big_array {
    double val[100];
} BigArray;

typedef struct str_by_ptr {
    char *s;
} StrByPtr;

void do_nothing(BigArray ba);

void do_nothing(BigArray ba) {
    printf("Hello!\n");
}

int main() {
    BigArray ba;
    do_nothing(ba);
    char buff[] = "helo";
    StrByPtr y1 = {.s = buff};
    StrByPtr y2 = y1;
    strcpy(buff, "fuga");
    printf("%s\n", y1.s);
    printf("%s\n", y2.s);
    printf("%p %p\n", y1.s, y2.s);
    return 0;
}
