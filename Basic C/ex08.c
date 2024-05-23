#include <stdio.h>

// Copying strings

int main(){
    int i;
    char s[6]="hello";
    char t[6];
    for(i=0;(t[i]=s[i])!='\0';i++);
    printf("The string s '%s' is now copied in the string t '%s'\n",s,t);
}