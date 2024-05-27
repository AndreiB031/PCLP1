#include "./utils.h"
#define OPT 8

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    int i = 0, j = 0;
    char DIR = 0, TIP = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = '.';
        }
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
        switch (DIR) {
            case 'S':
                switch (TIP) {
                    case '1':
                        mat[i][j] = mat[i-1][j] = mat[i-1][j-2] = mat[i-1][j-1] =
                        mat[i-1][j+1] = mat[i-1][j+2] = mat[i-2][j] =
                        mat[i-3][j-1] = mat[i-3][j] = mat[i-3][j+1] = '*';
                        break;
                    case '2':
                        mat[i][j] = mat[i-1][j-1] = mat[i-1][j] = mat[i-1][j+1] =
                        mat[i-2][j-3] = mat[i-2][j-2] = mat[i-2][j-1] = mat[i-2][j] =
                        mat[i-2][j+1] = mat[i-2][j+2] = mat[i-2][j+3] = mat[i-3][j] = mat[i-4][j-2] =
                        mat[i-4][j-1] = mat[i-4][j] = mat[i-4][j+1] = mat[i-4][j+2] = '*';
                        break;
                    default:
                        break;
                }
                break;
            case 'N':
                switch (TIP) {
                    case '1':
                        mat[i][j] = mat[i+1][j] = mat[i+1][j-2] = mat[i+1][j-1] = mat[i+1][j+1] =
                        mat[i+1][j+2] = mat[i+2][j] =
                        mat[i+3][j-1] = mat[i+3][j] = mat[i+3][j+1] = '*';
                        break;
                    case '2':
                        mat[i][j] = mat[i+1][j-1] = mat[i+1][j] = mat[i+1][j+1] = mat[i+2][j-3] =
                        mat[i+2][j-2] = mat[i+2][j-1] = mat[i+2][j] =
                        mat[i+2][j+1] = mat[i+2][j+2] = mat[i+2][j+3] = mat[i+3][j] = mat[i+4][j-2] =
                        mat[i+4][j-1] = mat[i+4][j] = mat[i+4][j+1] = mat[i+4][j+2] = '*';
                        break;
                    default:
                        break;
                }
                break;
            case 'E':
                switch (TIP) {
                    case '1':
                        mat[i][j] = mat[i-2][j-1] = mat[i-1][j-1] = mat[i][j-1] = mat[i+1][j-1] =
                        mat[i+2][j-1] =  mat[i][j-2] =
                        mat[i-1][j-3] = mat[i][j-3] = mat[i+1][j-3] = '*';
                        break;
                    case '2':
                        mat[i][j] = mat[i-1][j-1] = mat[i][j-1] = mat[i+1][j-1] = mat[i-3][j-2] =
                        mat[i-2][j-2] = mat[i-1][j-2] = mat[i][j-2] =
                        mat[i+1][j-2] = mat[i+2][j-2] = mat[i+3][j-2] = mat[i][j-3] = mat[i-2][j-4] =
                        mat[i-1][j-4] = mat[i][j-4] = mat[i+1][j-4] = mat[i+2][j-4] = '*';
                        break;
                    default:
                        break;
                }
                break;
            case 'W':
                switch (TIP) {
                    case '1':
                        mat[i][j] = mat[i-2][j+1] = mat[i-1][j+1] = mat[i][j+1] = mat[i+1][j+1] =
                        mat[i+2][j+1] =  mat[i][j+2] =
                        mat[i-1][j+3] = mat[i][j+3] = mat[i+1][j+3] = '*';
                        break;
                    case '2':
                        mat[i][j] = mat[i-1][j+1] = mat[i][j+1] = mat[i+1][j+1] = mat[i-3][j+2] =
                        mat[i-2][j+2] = mat[i-1][j+2] = mat[i][j+2] =
                        mat[i+1][j+2] = mat[i+2][j+2] = mat[i+3][j+2] = mat[i][j+3] = mat[i-2][j+4] =
                        mat[i-1][j+4] = mat[i][j+4] = mat[i+1][j+4] = mat[i+2][j+4] = '*';
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", mat[i][j]);
        }
        if (i != N - 1)
            printf("\n");
    }
}
