#include <stdio.h>
#define N 5

int main() {
    int sum = 0;
    int a[N] = {2, 6, 1, 4, 7};
    for (int *p = a; p < a + N; p++){
        sum += *p;
    }
    printf("%d\n", sum);
}
