#include <iostream>
#include <cstring>

constexpr int MAX_SIZE = 100;

int main() {
    int X[MAX_SIZE];
    int n;

    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid input. Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter %d integer values: ", n);
    for (int i = 0; i < n; ++i) {
        scanf_s("%d", &X[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += X[i];
        double average = static_cast<double>(sum) / (i + 1);
        X[i] = static_cast<int>(average);
    }

    printf("Smoothed array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", X[i]);
    }
    printf("\n");

    return 0;
}
