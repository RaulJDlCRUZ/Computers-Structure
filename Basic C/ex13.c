#include <stdio.h>

// Pointers and arrays

int main(){
    char *y, *z;
    char x[6]="hello";
    // Using the array name in an expression is equivalent to used the address of the array first element
    y = &x[0];
    z = x;
    printf("The pointer y points to the address %p which is the first element of the array x\n", y);
    printf("The pointer z also points to the address %p which is the first element of the array x\n", y);
    // *(y+i) is equivalent to x[i]
    printf("The content of x is '%c%c%c%c%c'\n", x[0], x[1], x[2], x[3], x[4]);
    printf("The content of x is '%c%c%c%c%c'\n", *y, *(y+1), *(y+2), *(y+3), *(y+4));
}