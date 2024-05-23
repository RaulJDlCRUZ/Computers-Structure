#include <stdio.h>

// Use of printf function to show variales in different formats

int main(){
    int n;
    n=511;
    printf("What is the value of %d in octal notation?\n",n);
    printf("%s! %d decimal is %o octal\n", "Correct",n,n);
}