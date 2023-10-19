#include <stdio.h>

int main() {
    int c = getchar();
    while (c != EOF) {
        putchar('/');  // 複写プログラムに加え、文字の間にスラッシュをいれる
        putchar(c);
        c = getchar();
    }
}
