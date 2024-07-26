#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int *ptr = (int *)0x7ffe637541f0;

    _printf("Pointer address: %p\n", ptr);
    _printf("%S\n", "Best\nSchool");
    return (0);
}
