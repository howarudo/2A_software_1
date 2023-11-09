#include <stdio.h>

void minmax(int a[], int n, int **min, int **max);
double avg_mat2(int *mat, int num_element);
void swap2(int n, char prefecture[][n], int i, int j);

int main() {
    int *min, *max;
    int arr[] = {3, 6, 9, 10};
    minmax(arr, 4, &min, &max);
    printf("min: %d, max: %d\n", *min, *max);

    double ave = avg_mat2(arr, 4);
    printf("ave: %lf\n", ave);

    char hokuriku2[][9] = {"toyama", "ishikawa", "fukui"};
    swap2(9, hokuriku2, 1, 2);  // "toyama", "fukui", "ishikawa"
    printf("%s\n%s\n%s\n", hokuriku2[0], hokuriku2[1], hokuriku2[2]);
}

void minmax(int a[], int n, int **min, int **max) {
    *min = &a[0];
    *max = &a[0];
    for (int i = 0; i < n; i++) {
        *min = a[i] < **min ? &a[i] : *min;
        *max = a[i] > **max ? &a[i] : *max;
    }
}

double avg_mat2(int *mat, int num_element) {
    double sum = 0.0;
    for (int i = 0; i < num_element; i++) {
        sum += mat[i];
    }
    return sum / num_element;
}

void swap2(int n, char prefecture[][n], int i, int j) {
    for (int len = 0; len < n; len++) {
        char tmp = prefecture[i][len];
        prefecture[i][len] = prefecture[j][len];
        prefecture[j][len] = tmp;
    }
}
