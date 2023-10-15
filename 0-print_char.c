#include "main.h"

/**
 * print_char - Entry point
 * @opaq : arguments
 *
 * Return: 1 for success
 */
int print_char(va_list opaq)
{
	char c;

	c = va_arg(val, int); /* extract argument from va_list */
	_putchar(c); /* print the character */
	return (1);
}
