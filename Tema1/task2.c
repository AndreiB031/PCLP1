#include <stdio.h>
#define NDim 100

int main() {
    int i = 0, N = 0, i2 = 0;
    float result = 0, vector[NDim] = {0};
    char operatii[NDim];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%f", &vector[i]);
    }
    if (i != 0) {
        scanf("%s", operatii);
    }
    for (i = 0; i < N - 1; i++) {
        if (operatii[i] == '*') {
            vector[i] *= vector[i + 1];
            for (i2 = i + 1; i2 < N; i2++) {
                vector[i2] = vector[i2 + 1];
                operatii[i2 - 1] = operatii[i2];
            }
            i--;
            N--;
        }
        if (operatii[i] == '/') {
            vector[i] /= vector[i + 1];
            for (i2 = i + 1; i2 < N; i2++) {
                vector[i2] = vector[i2 + 1];
                operatii[i2 - 1] = operatii[i2];
            }
            i--;
            N--;
        }
    }
     for (i = 0; i < N - 1; i++) {
        if (operatii[i] == '+') {
            vector[i] += vector[i + 1];
            for (i2 = i + 1; i2 < N; i2++) {
                vector[i2] = vector[i2 + 1];
                operatii[i2 - 1] = operatii[i2];
            }
            i--;
            N--;
        }
        if (operatii[i] == '-') {
            vector[i] -= vector[i + 1];
            for (i2 = i + 1; i2 < N; i2++) {
                vector[i2] = vector[i2 + 1];
                operatii[i2 - 1] = operatii[i2];
            }
            i--;
            N--;
        }
    }
    result = vector[0];
    printf("%f\n", result);
    return 0;
}
