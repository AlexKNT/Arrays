#include <cstdio>
#include <cstdlib>
#include <ctime>

void showArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6d%s", a[i], i % 10 == 9 ? "\n" : " ");
    }
    if (n % 10) {
        printf("\n");
    }
}

void smoothArray(int a[], int n) {
    int sum = 0; // Initialize a variable to keep track of the sum of elements.

    for (int i = 0; i < n; i++) {
        sum += a[i]; // Add the current element to the sum.
        a[i] = sum / (i + 1); // Calculate the mean by dividing the sum by the number of elements considered so far.
    }
}

void getUserInput(int arr[], int num_of_elements_in_arr) {
    for (int i = 0; i < num_of_elements_in_arr; i++) {
        printf("Enter element %d: ", i + 1);
        scanf_s("%d", &arr[i]);
    }
}

int main() {
    srand((unsigned)time(NULL)); // Initialize the random number generator.

    int arr[1000];
    int numberOfElementsInArray;
    printf("n = ");
    scanf_s("%i", &numberOfElementsInArray);
    getUserInput(arr, numberOfElementsInArray);

    printf("Original Array:\n");
    showArray(arr, numberOfElementsInArray); // Display the original array.

    smoothArray(arr, numberOfElementsInArray); // Call the smoothing function.

    printf("Smoothed Array:\n");
    showArray(arr, numberOfElementsInArray); // Display the smoothed array.

    printf("\n");
    return 0;
}
