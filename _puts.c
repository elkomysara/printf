#include "main.h"

int _puts(char *str, char *buffer, int *index)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i], buffer, index);
    }

    return (i);
}

