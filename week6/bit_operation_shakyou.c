#include <stdio.h>

void print_bit_uchar(unsigned char c) {
    for (int i = 0; i < 8; ++i) {
        if (c & 1 << (7 - i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    unsigned char num = 130;
    printf("%u\n", num);
    unsigned char left_most = num & 1;
    printf("%u\n", left_most);
    printf("%u\n", left_most >> 1 & 1);

    int i = 3;
    unsigned char mask = 1 << i;
    print_bit_uchar(mask);  // 00001000

    unsigned char a = 0b00000101;
    a = a | mask;  // aのうち、maskの位置にビットを立てる
    print_bit_uchar(a);  // 00001101

    return 0;

}
