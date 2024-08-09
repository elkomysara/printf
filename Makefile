
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = _printf.c print_percent.c print_char.c print_string.c print_integer.c print_binary.c _putchar.c format_reciever.c _puts.c
OBJ = $(SRC:.c=.o)
TARGET = printf

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
