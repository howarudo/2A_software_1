#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void rules();
void board();
int winChecker();
void fillPossibleSquare(int);

char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int possibleSquare[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int moveNumber = 1;
int valid = 0;
int gameOver = 0;

int main() {
    rules();
    while (gameOver == 0) {
        system("cls");
        board();
        char c = getchar();
        if (c != '\n') {
            int squareNumber = c -'0';
            if (possibleSquare[squareNumber] == 0 && squareNumber >= 0 && squareNumber <=9){
                square[squareNumber] = 'X';
                fillPossibleSquare(squareNumber);
                moveNumber = moveNumber + 1;
                valid = 0;
                c = '\n';
            } else {
                valid = 1;
                c = '\n';
            }
        }
        winChecker();
    }
    system("cls");
    board();
    return 0;
}

void rules() {
    printf("    Welcome to THE UNSPOKEN RULE\n");
    Sleep(2);
    printf("    Players take turns and choose a spot to do their business.\n");
    Sleep(5);
    printf("    But there's a catch...\n");
    Sleep(2);
    printf("    Players can't choose adjacents of occupied spots!\n");
    Sleep(5);
    printf("    Have fun lads! - Howard\n");
    Sleep(4);
}
void board() {
    char title[] = "          The Unspoken Rule\n\n";
    char lines[] = " ---------------------------------------\n";
    if (gameOver == 0) {
        if (valid == 0) {
            printf("%s", title);
            printf("%s", lines);
            printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", square[0], square[1], square[2], square[3], square[4], square[5], square[6], square[7], square[8], square[9]);
            printf("%s", lines);
            printf("    Player %d's turn!\n", moveNumber);
        } else {
            printf("%s", title);
            printf("%s", lines);
            printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", square[0], square[1], square[2], square[3], square[4], square[5], square[6], square[7], square[8], square[9]);
            printf("%s", lines);
            printf("    Player %d's turn!\n", moveNumber);
            printf("    No, uh oh! There's a better place to do your business!\n");

        }
    } else {
            printf("%s", title);
            printf("%s", lines);
            printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", square[0], square[1], square[2], square[3], square[4], square[5], square[6], square[7], square[8], square[9]);
            printf("%s", lines);
            printf("    Player %d LOSES!!! Shame on you...\n    You have to break THE UNSPOKEN RULE %s\n", moveNumber, "\U00002620");
    }
}

int winChecker() {
    int possible = 0;
    for (int i=0; i<10; i++) {
        if (possibleSquare[i] == 0) {
            possible = possible + 1;
        }
    }
    if (possible == 0){
        gameOver = 1;
        return 1;
    }
    return 0;
}

void fillPossibleSquare(int number) {
    if (number == 0) {
        possibleSquare[0] = 1;
        possibleSquare[1] = 1;
    } else if (number == 9) {
        possibleSquare[8] = 1;
        possibleSquare[9] = 1;
    } else {
        possibleSquare[number - 1] = 1;
        possibleSquare[number] = 1;
        possibleSquare[number + 1] = 1;
    }

}
