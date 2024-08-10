#include "../main.h"
#include <stdio.h>

/**
* main - Entry point for testing the _printf function
*
* Return: Always 0
*/
int main(void)
{
int len1, len2;

len1 = _printf("Binary: %b\n", 98);
len2 = printf("Binary: 1100010\n");
printf("Returned: _printf: %d, printf: %d\n", len1, len2);

return (0);
}
