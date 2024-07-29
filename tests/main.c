#include "../main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("Space flag: % d\n", 42);
    _printf("Plus flag: %+d\n", 42);
    _printf("Hash flag: %#x\n", 255);
    _printf("%S\n", "Best\nSchool");
    return (0);
}
