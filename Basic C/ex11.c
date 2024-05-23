#include <stdio.h>

// Declaring and using functions 

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int i, a=10, b=5;
    i=min(a,b);
    printf("The minimum between %d and %d is %d\n", a, b, i);
}