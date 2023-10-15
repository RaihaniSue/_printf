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
/* main prototype */
int _printf(const char *format, ...);
/**
 * struct format_specifier - Format specifier structure.
 * @specifier: The format specifier string.
 * @function: The associated printing function.
 */
typedef struct format_specifier
{
	char *specifier;
	int (*function)(va_list);
} format_specifier_t;
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
