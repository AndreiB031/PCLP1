#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
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
