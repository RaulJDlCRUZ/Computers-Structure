#include <stdio.h>

// While loop and use of getchar() and putchar() functions

int main(){
    char c;
    while(c!='\n'){
        c=getchar();
        putchar(c);
        putchar('\n');
    }
}