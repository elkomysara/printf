# _printf Project

## Description

This project is an implementation of the C standard library function `printf`. The `_printf` function produces output according to a format string.

## Requirements

- All files will be compiled on Ubuntu 20.04 LTS using `gcc`.
- All files should end with a new line.
- Code should use the Betty style.
- No global variables.
- No more than 5 functions per file.
- Allowed functions and macros: `write`, `malloc`, `free`, `va_start`, `va_end`, `va_copy`, `va_arg`.

## Conversion Specifiers

- `c`: Prints a character.
- `s`: Prints a string.
- `%`: Prints a percent symbol.

## Compilation

To compile the project, run:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c tests/main.c -o printf
# zero_day
# zero_day
