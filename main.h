#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
/* task four */
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1 /*deleting the buffer usinf -1 */
/* END OF TASK FOUR */
/* the putchar */
int _putchar(char c);
int _strlen(char *s);
#define NULL_STRING "(null)"
/**
  * struct code_format - Struct format
  *
  * @sc: The specifiers
  * @f: The function associated
  */
typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;
/* main prototype */
int _printf(const char *format, ...);

/* task zero */
int print_char(va_list opaq);
int print_string(va_list opaq);
int print_percent(va_list opaq);

/* task one */
int print_int(va_list opaq);

/* task two */
int print_binary_unsigned(va_list opaq);

/* task three */
int print_hexadecimal(va_list opaq);
int print_HEXADECIMAL(va_list opaq);
int print_octal(va_list opaq);
int print_unsigned(va_list opaq);

/* task five */
int print_hex_of_non_visible_char(va_list opaq);

/* task six */
int print_b_address(va_list opaq);
int print_conversion_hexadecimal(unsigned long int n);

/* task eight */
/*task fourteen*/
int print_rot13(va_list opaq);




#endif
