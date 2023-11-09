#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nums[argc - 1];
    for (int i =1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        sum += nums[i];
    }
    printf("%d\n", sum);
}
