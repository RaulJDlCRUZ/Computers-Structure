#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char cad[MAX];
    int n = 0;

    fgets(cad, MAX, stdin);

    while(cad[n++] != '\0')
        if(cad[n - 1] >= 'A' &&  cad[n - 1] <= 'Z') cad[n - 1] = cad[n - 1] - 'A' + 'a';
        
    printf("%s\n", cad);

    return 0;
}