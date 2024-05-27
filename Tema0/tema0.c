#include <stdio.h>

int main() {
    int N = 0;
    int i = 0;
    const int Trick = 7;
    const int Treat = 11;
    printf("Introduceti valoarea numarului natural N:\n");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        if (i%Trick == 0&&i%Treat != 0) {
            printf("Trick");
        }
        if (i%Trick != 0&&i%Treat == 0) {
            printf("Treat");
        }
        if (i%Trick == 0&&i%Treat == 0) {
            printf("TrickOrTreat");
        }
        if (i%Trick != 0&&i%Treat != 0) {
            printf("%d", i);
        }
        if (i != N) {
            printf(" ");
        }
    }
    return 0;
}
