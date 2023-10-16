#include <cstdio>
#include <cstdlib>
#include <ctime>
#define LIGHTRED 91
#define LIGHTGREEN 92

void setTextColor(int color) {
    printf("\033[%im", color);
}

void resetTextColor() {
    printf("\033[0m");
}

void randomArray(float a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = (rand() / float(RAND_MAX)) * 200 - 100;
    }
}

void showArray(float a[], int n, int redPos, int greenPos) {
    for (int i = 0; i < n; i++) {
        if (i == redPos) {
            setTextColor(LIGHTRED);
        }
        else if (i == greenPos) {
            setTextColor(LIGHTGREEN);
        }
        printf("%6.2f%s", a[i], i % 10 == 9 ? "\n" : " ");
        resetTextColor();
    }
    if (n % 10) {
        printf("\n");
    }
}

int getMaxPos(float a[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }
    return max;
}

int getMinPos(float a[], int n) {
    int min = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min]) {
            min = i;
        }
    }
    return min;
}

int main() {
    srand((unsigned)time(NULL)); // Inicializēt gadījumskaitļu ģeneratoru
    float a[1000];
    int n;
    printf("n = ");
    scanf_s("%i", &n);
    randomArray(a, n);
    int maxPos = getMaxPos(a, n);
    int minPos = getMinPos(a, n);
    showArray(a, n, maxPos, minPos);
    printf("\n");
    return 0;
}
