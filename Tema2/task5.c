#include "./utils.h"
#define PATRU 4
#define CINCI 5

void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N) {
    int i_av[nr_avioane], j_av[nr_avioane], viteza[nr_avioane];
    int nr_avion = 0, verif = 1, count = 0, T_parc = 0, i = 0, j = 0;
    char DIR[nr_avioane], TIP[nr_avioane];
    int mat[N + CINCI][N + CINCI];
    for (i = 0; i < N + CINCI; i++) {
        for (j = 0; j < N + CINCI; j++) {
            mat[i][j] = 0;
        }
    }

    for (i = 0; i < nr_pct_coord; i++) {
        mat[X[i]][Y[i]] = 1;
    }

    for (nr_avion = 0; nr_avion < nr_avioane; nr_avion++) {
        i_av[nr_avion] = (*(short int*)info);
        info += sizeof(short int);
        j_av[nr_avion] = (*(short int*)info);
        info += sizeof(short int);
        DIR[nr_avion] = (*(char*)info);
        info += sizeof(char);
        TIP[nr_avion] = (*(char*)info);
        info +=  PATRU * sizeof(char);
        viteza[nr_avion] = (*(int*)info);
        info +=  PATRU * sizeof(char);
    }

    for (T_parc = 0; T_parc <= T; T_parc++) {
    count = 0;
        for (nr_avion = 0; nr_avion < nr_avioane; nr_avion++) {
            i = i_av[nr_avion];
            j = j_av[nr_avion];
            verif = 0;
            switch (DIR[nr_avion]) {
            case 'S':
                switch (TIP[nr_avion]) {
                    case '1':
                        if (i < N)
                            if (mat[i][j] || mat[i-1][j] || mat[i-1][j-2] || mat[i-1][j-1] ||
                                mat[i-1][j+1] || mat[i-1][j+2] || mat[i-2][j] ||
                                mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                verif = 1;
                        if (i == N)
                            if (mat[i-1][j] || mat[i-1][j-2] || mat[i-1][j-1] ||
                                mat[i-1][j+1] || mat[i-1][j+2] || mat[i-2][j] ||
                                mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                verif = 1;
                        if (i == N + 1)
                            if (mat[i-2][j] || mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                verif = 1;
                        if (i == N + 2)
                            if (mat[i-3][j-1] || mat[i-3][j] || mat[i-3][j+1])
                                verif = 1;
                        i_av[nr_avion] += viteza[nr_avion];
                        break;
                    case '2':
                        if (i < N)
                            if (mat[i][j] || mat[i-1][j-1] || mat[i-1][j] || mat[i-1][j+1] ||
                                mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                verif = 1;
                        if (i == N)
                            if (mat[i-1][j-1] || mat[i-1][j] || mat[i-1][j+1] ||
                                mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                verif = 1;
                        if (i == N + 1)
                            if (mat[i-2][j-3] || mat[i-2][j-2] || mat[i-2][j-1] || mat[i-2][j] ||
                                mat[i-2][j+1] || mat[i-2][j+2] || mat[i-2][j+3] || mat[i-3][j] || mat[i-4][j-2] ||
                                mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                verif = 1;
                        if (i == N + 2)
                            if (mat[i-3][j] || mat[i-4][j-2] ||
                                mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                verif = 1;
                        if (i == N + 3)
                            if (mat[i-4][j-2] || mat[i-4][j-1] || mat[i-4][j] || mat[i-4][j+1] || mat[i-4][j+2])
                                verif = 1;
                        i_av[nr_avion] += viteza[nr_avion];
                        break;
                    default:
                        break;
                }
                break;
            case 'N':
                switch (TIP[nr_avion]) {
                    case '1':
                        if (i >= 0)
                            if (mat[i][j] || mat[i+1][j] || mat[i+1][j-2] || mat[i+1][j-1] || mat[i+1][j+1] ||
                                mat[i+1][j+2] || mat[i+2][j] ||
                                mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                verif = 1;
                        if (i == -1)
                            if (mat[i+1][j] || mat[i+1][j-2] || mat[i+1][j-1] ||
                                mat[i+1][j+1] || mat[i+1][j+2] || mat[i+2][j] ||
                                mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                verif = 1;
                        if (i == -2)
                            if (mat[i+2][j] || mat[i+3][j-1] || mat[i+3][j] || mat[i+3][j+1])
                                verif = 1;
                        if (i == -3)
                            if (mat[i+3][j] || mat[i+3][j+1])
                                verif = 1;
                        i_av[nr_avion] -= viteza[nr_avion];
                        break;
                    case '2':
                        if (i >= 0)
                            if (mat[i][j] | mat[i+1][j-1] || mat[i+1][j] || mat[i+1][j+1] || mat[i+2][j-3] ||
                                mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                verif = 1;
                        if (i == -1)
                            if (mat[i+1][j-1] || mat[i+1][j] || mat[i+1][j+1] || mat[i+2][j-3] ||
                                mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                verif = 1;
                        if (i == -2)
                            if (mat[i+2][j-3] || mat[i+2][j-2] || mat[i+2][j-1] || mat[i+2][j] ||
                                mat[i+2][j+1] || mat[i+2][j+2] || mat[i+2][j+3] || mat[i+3][j] || mat[i+4][j-2] ||
                                mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                verif = 1;
                        if (i == -3)
                            if (mat[i+3][j] || mat[i+4][j-2] ||
                                mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                verif = 1;
                        if (i == -4)
                            if (mat[i+4][j-2] || mat[i+4][j-1] || mat[i+4][j] || mat[i+4][j+1] || mat[i+4][j+2])
                                verif = 1;
                        i_av[nr_avion] -= viteza[nr_avion];
                        break;
                    default:
                        break;
                }
                break;
            case 'E':
                switch (TIP[nr_avion]) {
                    case '1':
                        if (j < N)
                            if (mat[i][j] || mat[i-2][j-1] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] ||
                                mat[i+2][j-1] ||  mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                verif = 1;
                        if (j == N)
                            if ( mat[i-2][j-1] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] ||
                                mat[i+2][j-1] ||  mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                verif = 1;
                        if (j == N + 1)
                            if (mat[i][j-2] || mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                verif = 1;
                        if (j == N + 2)
                            if (mat[i-1][j-3] || mat[i][j-3] || mat[i+1][j-3])
                                verif = 1;
                        j_av[nr_avion] += viteza[nr_avion];
                        break;
                    case '2':
                        if (j < N)
                            if (mat[i][j] || mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] || mat[i-3][j-2] ||
                                mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                verif = 1;
                        if (j == N)
                            if (mat[i-1][j-1] || mat[i][j-1] || mat[i+1][j-1] || mat[i-3][j-2] ||
                                mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                verif = 1;
                        if (j == N + 1)
                            if (mat[i-3][j-2] || mat[i-2][j-2] || mat[i-1][j-2] || mat[i][j-2] ||
                                mat[i+1][j-2] || mat[i+2][j-2] || mat[i+3][j-2] || mat[i][j-3] || mat[i-2][j-4] ||
                                mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                verif = 1;
                        if (j == N + 2)
                            if (mat[i][j-3] || mat[i-2][j-4] ||
                                mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                verif = 1;
                        if (j == N + 3)
                            if (mat[i-2][j-4] || mat[i-1][j-4] || mat[i][j-4] || mat[i+1][j-4] || mat[i+2][j-4])
                                verif = 1;
                        j_av[nr_avion] += viteza[nr_avion];
                        break;
                    default:
                        break;
                }
                break;
            case 'W':
                switch (TIP[nr_avion]) {
                    case '1':
                        if (j >= 0)
                            if (mat[i][j] || mat[i-2][j+1] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] ||
                                mat[i+2][j+1] ||  mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                verif = 1;
                        if (j == -1)
                            if (mat[i-2][j+1] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] ||
                                mat[i+2][j+1] ||  mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                verif = 1;
                        if (j == -2)
                            if (mat[i][j+2] || mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                verif = 1;
                        if (j == -3)
                            if (mat[i-1][j+3] || mat[i][j+3] || mat[i+1][j+3])
                                verif = 1;
                        j_av[nr_avion] -= viteza[nr_avion];
                        break;
                    case '2':
                        if (j >= 0)
                            if (mat[i][j] || mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] || mat[i-3][j+2] ||
                                mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                verif = 1;
                        if (j == -1)
                            if (mat[i-1][j+1] || mat[i][j+1] || mat[i+1][j+1] || mat[i-3][j+2] ||
                                mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                verif = 1;
                        if (j == -2)
                            if (mat[i-3][j+2] || mat[i-2][j+2] || mat[i-1][j+2] || mat[i][j+2] ||
                                mat[i+1][j+2] || mat[i+2][j+2] || mat[i+3][j+2] || mat[i][j+3] || mat[i-2][j+4] ||
                                mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                verif = 1;
                        if (j == -3)
                            if (mat[i][j+3] || mat[i-2][j+4] ||
                                mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                verif = 1;
                        if (j == -4)
                            if (mat[i-2][j+4] || mat[i-1][j+4] || mat[i][j+4] || mat[i+1][j+4] || mat[i+2][j+4])
                                verif = 1;
                        j_av[nr_avion] -= viteza[nr_avion];
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
        count = count + verif;
        }
    printf("%d: ", T_parc);
    printf("%d\n", count);
    }
}
