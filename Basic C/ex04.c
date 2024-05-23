#include <stdio.h>

// Transforming letters from capital to lower case

int main( ){
    char c;
    while((c=getchar())!='\n'){
        if('A'<=c && c<='Z')
            putchar(c+'a'-'A');
        else
            putchar(c);
    }
    putchar('\n');
}