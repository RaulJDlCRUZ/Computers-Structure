#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("Program Name: %s\t %d arguments\n", argv[0], argc); 

    if(argc == 1){
        printf("\nNo string passed.\n"); 
        return 1;
    }
        
    char cad[strlen(argv[1])];
    int n = 0;
    while(argv[1][n++] != '\0'){
        cad[strlen(argv[1]) - n] = argv[1][n - 1];
    }
    printf("%s\n", cad);

    return 0; 
} 