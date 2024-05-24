#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isInteger(const char *str)
{
    if (*str == '-')
    {
        str++;
    }
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stdout, "Use: ./main <number>\n");
        return 1;
    }

    if (!isInteger(argv[1]))
    {
        fprintf(stdout, "Error: El argumento debe ser un número entero válido.\n");
        return 1;
    }

    fprintf(stdout, "%08x\n", atoi(argv[1]));
    return 0;
}