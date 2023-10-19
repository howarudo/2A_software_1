#include <stdio.h>

int main() {
    char numbers[] = "  0    5   10   15\n";
    char arrows[] = "--+----+----+----+-->\n";
    char letter = getchar();
    while (letter != EOF) {
        char comma = getchar();
        char intChar = getchar();
        int number = 0;
        printf("%c, %d\n", letter, number);
        while (intChar != EOF && intChar != '\n' && intChar != ',') {
            number = number * 10 + intChar - '0';
            intChar = getchar();
        }
        arrows[number+2] = letter;
        printf("%s", numbers);
        printf("%s", arrows);
        letter = getchar();
    }

    return 0;
}
