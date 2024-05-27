#include <stdio.h>
#define nr_biti_op 27
#define COMP_4_biti 15
#define start_op 29
#define size_number 16
int main() {
    unsigned int inst = 0, N = 0, Dim = 0, delim_operatii = 3, operatie = 0;
    unsigned int parc_operatii = nr_biti_op;
    unsigned int dim_totala_nr = 0, mux = 0, parcurgere_short = 0, Dim_biti = 1;
    unsigned short numar = 0;
    int rezultat = 0, i = 0;
    scanf("%u", &inst);
    N = inst;
    N = (N >> start_op);
    N++;
    Dim = ((inst >> (nr_biti_op - 2 * (N + 1))) & COMP_4_biti);
    Dim++;
    for (i = 1; i < Dim; i++) {
        Dim_biti = (Dim_biti << 1);
        Dim_biti++;
    }
    dim_totala_nr = ((N + 1) * Dim);
    parc_operatii += 2;
    while (dim_totala_nr) {
        scanf("%hu", &numar);
        mux = 1;
        parcurgere_short = size_number - Dim;
        while (Dim * mux <= size_number) {
            if (parc_operatii == start_op) {
                rezultat = ((numar >> parcurgere_short));
            } else {
                operatie = ((inst >> parc_operatii) & delim_operatii);
                if (operatie == 0) {
                    rezultat += (int)((numar >> parcurgere_short) & Dim_biti);
                }
                if (operatie == 1) {
                    rezultat -= (int)((numar >> parcurgere_short) & Dim_biti);
                }
                if (operatie == 2) {
                    rezultat *= (int)((numar >> parcurgere_short) & Dim_biti);
                }
                if (operatie == 3) {
                    rezultat /= (int)((numar >> parcurgere_short) & Dim_biti);
                }
            }
            parcurgere_short -= Dim;
            parc_operatii -= 2;
            mux++;
            dim_totala_nr -= Dim;
            if (dim_totala_nr == 0)
                break;
        }
    }
    printf("%d\n", rezultat);


    return 0;
}
