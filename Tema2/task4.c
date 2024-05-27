#include "./utils.h"
#define OPT 8
/// @brief
/// @param info
/// @param nr_avioane
/// @param nr_obstacole
/// @param x
/// @param y
/// @param N
void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    int i = 0, j = 0, verif = 1, count = 0;
    char DIR = 0, TIP = 0;
    int **mat = (int**)calloc(N, sizeof(int*));
    for (i = 0; i < N; i++) {
        mat[i] = (int*)calloc(N, sizeof(int));
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = 0;
        }
    }
    for (i = 0; i < nr_obstacole; i++) {
        mat[x[i]][y[i]] = 1;
    }
    for (int parc = 0; parc < nr_avioane; parc++) {
        i = (*(short int*)info);
        info += sizeof(short int);
        j = (*(short int*)info);
        info += sizeof(short int);
        DIR = (*(char*)info);
        info += sizeof(char);
        TIP = (*(char*)info);
        info +=  OPT * sizeof(char);
        verif = 1;
        switch (DIR) {
            case 'S':
                switch (TIP) {
                    case '1':
                        while (i < N + 3) {
                            if (i < N)
                                if (mat[i][j] || mat[i-1][j] || mat[i-1][j-2] || mat[i-1][j-1] ||
                                    mat[i-1][j+1] || mat[i-1][j+2] || mat[i-2][j] ||
                                    mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                    verif = 0;
                            if (i == N)
                                if (mat[i-1][j] || mat[i-1][j-2] || mat[i-1][j-1] ||
                                    mat[i-1][j+1] || mat[i-1][j+2] || mat[i-2][j] ||
                                    mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                    verif = 0;
                            if (i == N + 1)
                                if (mat[i-2][j] || mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                    verif = 0;
                            if (i == N + 2)
                                if (mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                    verif = 0;
                            i++;
                        }
                        break;
                    case '2':
                        while (i < N + 4) {
                            if (i < N)
                                if (mat[i][j] || mat[i-1][j-1] || mat[i-1][j] || mat[i-1][j+1] ||
                                    mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                    mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                    mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                    verif = 0;
                            if (i == N)
                                if (mat[i-1][j-1] || mat[i-1][j] || mat[i-1][j+1] ||
                                    mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                    mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                    mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                    verif = 0;
                            if (i == N + 1)
                                if (mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                    mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                    mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                    verif = 0;
                            if (i == N + 2)
                                if (mat[i-3][j] || mat[i-4][j-2] ||
                                    mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                    verif = 0;
                            if (i == N + 3)
                                if (mat[i-4][j-2] || mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                    verif = 0;
                        i++;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 'N':
                switch (TIP) {
                    case '1':
                        while (i >= -3) {
                            if (i >= 0)
                                if (mat[i][j] || mat[i+1][j] || mat[i+1][j-2] || mat[i+1][j-1] || mat[i+1][j+1] ||
                                    mat[i+1][j+2] || mat[i+2][j] ||
                                    mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                    verif = 0;
                            if (i == -1)
                                if (mat[i+1][j] || mat[i+1][j-2] || mat[i+1][j-1] ||
                                    mat[i+1][j+1] || mat[i+1][j+2] || mat[i+2][j] ||
                                    mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                    verif = 0;
                            if (i == -2)
                                if (mat[i+2][j] || mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                    verif = 0;
                            if (i == -3)
                                if (mat[i+3][j] || mat[i+3][j+1])
                                    verif = 0;
                        i--;
                        }
                        break;
                    case '2':
                        while (i >= -4) {
                            if (i >= 0)
                                if (mat[i][j] | mat[i+1][j-1] || mat[i+1][j] || mat[i+1][j+1] || mat[i+2][j-3] ||
                                    mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                    mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                    mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                    verif = 0;
                            if (i == -1)
                                if (mat[i+1][j-1] || mat[i+1][j] || mat[i+1][j+1] || mat[i+2][j-3] ||
                                    mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                    mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                    mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                    verif = 0;
                            if (i == -2)
                                if (mat[i+2][j-3] || mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                    mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                    mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                    verif = 0;
                            if (i == -3)
                                if (mat[i+3][j] || mat[i+4][j-2] ||
                                    mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                    verif = 0;
                            if (i == -4)
                                if (mat[i+4][j-2] || mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                    verif = 0;
                            i--;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 'E':
                switch (TIP) {
                    case '1':
                        while (j < N + 3) {
                            if (j < N)
                                if (mat[i][j] || mat[i-2][j-1] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] ||
                                    mat[i+2][j-1] ||  mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                    verif = 0;
                            if (j == N)
                                if ( mat[i-2][j-1] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] ||
                                    mat[i+2][j-1] ||  mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                    verif = 0;
                            if (j == N + 1)
                                if (mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                    verif = 0;
                            if (j == N + 2)
                                if (mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                    verif = 0;
                            j++;
                        }
                        break;
                    case '2':
                        while (j < N + 4) {
                            if (j < N)
                                if (mat[i][j] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] || mat[i-3][j-2] ||
                                    mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                    mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                    mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                    verif = 0;
                            if (j == N)
                                if (mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] || mat[i-3][j-2] ||
                                    mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                    mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                    mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                    verif = 0;
                            if (j == N + 1)
                                if (mat[i-3][j-2] || mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                    mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                    mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                    verif = 0;
                            if (j == N + 2)
                                if (mat[i][j-3] || mat[i-2][j-4] ||
                                    mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                    verif = 0;
                            if (j == N + 3)
                                if (mat[i-2][j-4] || mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                    verif = 0;
                            j++;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 'W':
                switch (TIP) {
                    case '1':
                        while (j >= -3) {
                            if (j >= 0)
                                if (mat[i][j] || mat[i-2][j+1] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] ||
                                    mat[i+2][j+1] ||  mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                    verif = 0;
                            if (j == -1)
                                if (mat[i-2][j+1] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] ||
                                    mat[i+2][j+1] ||  mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                    verif = 0;
                            if (j == -2)
                                if (mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                    verif = 0;
                            if (j == -3)
                                if (mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                    verif = 0;
                            j--;
                        }
                        break;
                    case '2':
                         while (j >= -4) {
                            if (j >= 0)
                                if (mat[i][j] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] || mat[i-3][j+2] ||
                                    mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                    mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                    mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                    verif = 0;
                            if (j == -1)
                                if (mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] || mat[i-3][j+2] ||
                                    mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                    mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                    mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                    verif = 0;
                            if (j == -2)
                                if (mat[i-3][j+2] || mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                    mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                    mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                    verif = 0;
                            if (j == -3)
                                if (mat[i][j+3] || mat[i-2][j+4] ||
                                    mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                    verif = 0;
                            if (j == -4)
                                if (mat[i-2][j+4] || mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                    verif = 0;
                            j--;
                         }
                         break;
                    default:
                        break;
                }
            default:
                break;
        }
        count += verif;
    }
    printf("%d", count);
}
