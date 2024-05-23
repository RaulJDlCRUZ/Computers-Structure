#include <stdio.h>

// Length of an string

int length(char s[]){
    int n;
    for(n=0; s[n] != '\0';)
    n++;
    return n;
}

int main(){
    char x[]="hello World";
    int l;
    l=length(x);
    printf("The length of the string x '%s' is %d\n", x, l);
}