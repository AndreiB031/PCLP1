#include <stdio.h>
#define NDim 100

int main() {
    int i = 0, N = 0, vector[NDim] = {0};
    float result = 0;
    char operatii[NDim];
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &vector[i]);
    }
    if (i != 0) {
        scanf("%s", operatii);
    }
    result = (float)vector[0];
    for (i = 0; i < N - 1; i++) {
        if (operatii[i] == '+') {
            result += (float)vector[i + 1];
        }
        if (operatii[i] == '-') {
            result -= (float)vector[i + 1];
        }
        if (operatii[i] == '/') {
            result /= (float)vector[i + 1];
        }
        if (operatii[i] == '*') {
            result *= (float)vector[i + 1];
        }
    }
    printf("%f\n", result);
    return 0;
}
