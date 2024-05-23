#include <stdio.h>

// Using vectors (arrays) of characters (strings)

int main(){
    int n, c; char line[100];
    n = 0;
    while((c=getchar()) != '\n'){
        if( n < 100 ){ 
            line[n] = c;
            n++;
         }
    }
    printf("The string array %s has %d elements\n",line,n);
}