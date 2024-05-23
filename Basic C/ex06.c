#include <stdio.h>

// preincrementing and postincrementing variables

int main(){
    int a, b, x, y;
    a = b = 5;
    x = a++;
    y = ++b;
    printf("a=%d, b=%d, x=%d and y=%d\n",a,b,x,y);
}