#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char cad[MAX];
    int count, n;
    count = n = 0;

    fgets(cad, MAX, stdin);

    while(cad[n++] != '\0')
        if(cad[n - 1] == ' ') count++;
        
    printf("It has %d white spaces\n", count);

    return 0;
}