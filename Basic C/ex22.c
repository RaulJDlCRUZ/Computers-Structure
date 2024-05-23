#include <stdio.h>

// Little Endian or Big Endian?

int main(){
    char c;
    char *pc=&c;
	int i=0xAABBCCDD;
    int *pi=&i;
    printf("pi %p, pi+1 %p, i %X\n", pi, pi+1, i);
    printf("pc+1 %p, *(pc+) %X\n",pc+1, *(pc+1));
    printf("pc+2 %p, *(pc+2) %X\n",pc+2, *(pc+2));
    printf("pc+3 %p, *(pc+3) %X\n",pc+3, *(pc+3));
    printf("pc+4 %p, *(pc+4) %X\n",pc+4, *(pc+4));
    if (*(pc+1)==0xFFFFFFAA)
        printf("The byte content in the address pc+1 %p is %p and therefore our computer is Big Endian\n", pc+1, *(pc+1));
        else
        printf("The byte content in the address pc+1 %p is %p and therefore our computer is Little Endian\n", pc+1, *(pc+1));
}