#include "../main.h"

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
    int *ptr = (int *)0x7ffe637541f0;
    _printf("Pointer address: %p\n", ptr);
    return (0);
}
