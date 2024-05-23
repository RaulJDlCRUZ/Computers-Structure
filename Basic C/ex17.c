#include <stdio.h>

// Use of switch case

int main(){
    char c;
    int aflag=0, bflag=0, cflag=0, other=0;
    while((c=getchar())!='\n'){
        switch(c) {
            case 'a':
            aflag++;
            break;
            case 'b':
            bflag++;
            break;
            case 'c':
            cflag++;
            break;
            default:
            other++;
        }
    }
    printf("The number of a's, b's, c's and other characters is: %d, %d, %d and %d, respectively\n", aflag, bflag, cflag, other);
}