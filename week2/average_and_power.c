#include <stdio.h>

float average(int a, int b);
int power(int a, int b);

int main() {
    int a; int b;
    printf("Give me 2 numbers!\n");
    scanf("%d %d", &a, &b);
    float ans = average(a, b);
    printf("Their average is %f\n", ans);
    printf("(first) ^ (second) =  %d\n", power(a, b));
    return 0;
}

float average(int a, int b) {
    float ans = (a + b) / 2.0;
    return ans;
}

int power(int a, int b) {
    // a ^ b for b positive
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = ans * a;
    }
    return ans;
}
