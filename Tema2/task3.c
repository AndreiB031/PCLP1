#include "./utils.h"
#define CINCI 5
#define SASE 6
#define SAPTE 7
#define OPT 8
#define NOUA 9
#define SIZE 13


/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/
int comparator(const void * p1, const void * p2) {
        if ((*((char*)p1 + CINCI * sizeof(char)) - *((char*)p2 + CINCI * sizeof(char))) != 0) {
            return (*((char*)p1 + CINCI * sizeof(char)) - *((char*)p2 + CINCI * sizeof(char)));
        } else {
            if ((*((char*)p2 + SASE * sizeof(char)) - *((char*)p1 + SASE * sizeof(char))) != 0) {
                return (*((char*)p2 + SASE * sizeof(char)) - *((char*)p1 + SASE * sizeof(char)));
            } else {
                if ((*((char*)p2 + SAPTE * sizeof(char)) - *((char*)p1 + SAPTE * sizeof(char))) != 0) {
                    return (*((char*)p2 + SAPTE * sizeof(char)) - *((char*)p1 + SAPTE * sizeof(char)));
                } else {
                    if ((*((char*)p2 + OPT * sizeof(char)) - *((char*)p1 + OPT * sizeof(char))) != 0) {
                        return (*((char*)p2 + OPT * sizeof(char)) - *((char*)p1 + OPT * sizeof(char)));
                    } else {
                        if ((*((int*)p1 +NOUA * sizeof(char)) - *((int*)p2 +NOUA * sizeof(char))) != 0) {
                            return (*((char*)p1 +NOUA * sizeof(char)) - *((char*)p2 +NOUA * sizeof(char)));
                        }
                    }
                }
            }
        }
}
void SolveTask3(void *info, int nr_avioane) {
    qsort(info, nr_avioane, SIZE * sizeof(char), comparator);
    for (int i = 0; i < nr_avioane; i++) {
        printf("(%hd, ", *(short int*)info);
        info += sizeof(short int);
        printf("%hd)\n", *(short int*)info);
        info += sizeof(short int);
        printf("%c\n", *(char*)info);
        info += sizeof(char);
        printf("%c", *(char*)info);
        info += sizeof(char);
        printf("%c", *(char*)info);
        info += sizeof(char);
        printf("%c", *(char*)info);
        info += sizeof(char);
        printf("%c\n", *(char*)info);
        info += sizeof(char);
        printf("%d\n", *(int*)info);
        info += sizeof(int);
        printf("\n");
    }
}
