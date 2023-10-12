#include <stdio.h>

int get_digit_number(int);

int main() {
    int N = 10;
    // Initialize array to hold coin values and number of coins for each value
    int coin_values[] = {100, 50, 10, 5, 1};
    int coin_number[] = {0, 0, 0, 0, 0};
    // max_coin_num will store the maximum number of coins (for printing)
    int max_coin_num = 1;
    for (int i = 0; i < 5; i++) {
        // coin number is number of coins needed for that value. then update N
        coin_number[i] = N / coin_values[i];
        N = N - coin_number[i] * coin_values[i];
        if (coin_number[i] > max_coin_num) {
            max_coin_num = coin_number[i];
        }
        // Printing format
        for (int j = 0; j < max_coin_num - coin_number[i]; j++) {
            printf(" ");
        }
        for (int j = 0; j < coin_number[i]; j++) {
            printf("*");
        }
        printf(" : ");
        // Get the number of digits to make add space infront of value
        int coin_value_digits = get_digit_number(coin_values[i]);
        for (int j = 0; j < 3 - coin_value_digits; j++) {
            printf(" ");
        }
        printf("%d yen\n", coin_values[i]);
    }
}

int get_digit_number(int coin_value) {
    // Returns number of digit of a value
    // 100 -> 3, 10 -> 2, 8 -> 1
    int digits = 0;
    while (coin_value != 0) {
        coin_value = coin_value / 10;
        digits = digits + 1;
    }
    return digits;
}
