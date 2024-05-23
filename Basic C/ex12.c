#include <stdio.h>

// Use of pointers

int main(){
    int a, *b, c;
    a = 10;
    b = &a;
    c = *b;
    printf("The variable a is stored in the address %p and contains the value %d\n", &a, a);
    printf("The pointer b points to the address %p which contains the value %d\n", b, *b);
    printf("The variable c is stored in the address %p and contains the value %d\n", &c, c);
}