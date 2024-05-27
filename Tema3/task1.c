#include <stdio.h>
#define nr_biti_op 27
#define COMP 15
#define start_op 29
int main() {
    unsigned int inst = 0, nr_operatii = 0, delim_operatii = 3, operatie = 0, parc = nr_biti_op, comp = COMP, DIM = 0;
    scanf("%u", &inst);
    nr_operatii = inst;
    nr_operatii = (nr_operatii >> start_op);
    nr_operatii++;
    printf("%u ", nr_operatii);
    while (nr_operatii--) {
        operatie = inst;
        operatie = (operatie >> parc);
        operatie = (operatie & delim_operatii);
        if (operatie == 0) {
            printf("+ ");
        }
        if (operatie == 1) {
            printf("- ");
        }
        if (operatie == 2) {
            printf("* ");
        }
        if (operatie == 3) {
            printf("/ ");
        }
        parc -= 2;
    }
    parc -= 2;
    DIM = (inst >> parc);
    DIM = (DIM & comp);
    DIM++;
    printf("%u\n", DIM);
    return 0;
}
