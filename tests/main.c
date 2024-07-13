#include "main.h"
#include <stdio.h> 
int main(void)
{
char *str = "Hello, world!";
int num = 12345;
unsigned int unum = 54321;
char ch = 'A';
void *ptr = &num;

_printf("String:[%s]\n", str);
_printf("Character:[%c]\n", ch);
_printf("Integer:[%d]\n", num);
_printf("Unsigned:[%u]\n", unum);
_printf("Hexadecimal:[%x]\n", unum);
_printf("Pointer:[%p]\n", ptr);
_printf("Percent:[%%]\n");

return (0);
}


