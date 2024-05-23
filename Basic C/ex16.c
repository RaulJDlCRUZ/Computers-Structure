#include <stdio.h>

// Program with arguments. It must be executed from the command line as: ./ex16 arg
// Where arg is a string of characters such as "FRedRT".

int main(int argc, char*argv[]){
    if(argc>1) {
        int i;
        char c;
        for(i=1; (c=argv[1][i]) != '\0'; i++){
            if('A'<=c && c<='Z')
                putchar(c+'a'-'A');
            else
                putchar(c);
        }
        putchar('\n');
    }
}
