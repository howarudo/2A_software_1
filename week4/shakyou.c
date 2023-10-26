#include <stdio.h>
#define N 5

int strlen3(const char *s);

int main() {
    // int sum = 0;
    // int a[N] = {2, 6, 1, 4, 7};
    // for (int *p = a; p < a + N; p++){
    //     sum += *p;
    // }
    // printf("%d\n", sum);
    char array[] = "abc";
    char *q = array;
    int result = strlen3(q);
    printf("%d", result);
}

int strlen3(const char *s) {
    const char *p = s;
    while (*s) {
        s++;
    }
    return &s - *p;
}
