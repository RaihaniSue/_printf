#include "main.h"

/**
 * print_b_address - Entry point
 * @opaq : the set of parameters
 *
 * Return: the number of characters printed
 */
int print_b_address(va_list opaq)
{
	void *pointer; /* Declare a void pointer */
	char *x = "(nil)"; /* Initialize a string with "(nil)" */
	long int l; /* Declare a long integer */
	int i; /* Declare an integer */

	pointer = va_arg(opaq, void*); /* Extract the void pointer argument */
	if (pointer == NULL) /* Check if the pointer is NULL */
	{
		for (i = 0; x[i] != '\0'; i++)
			_putchar(x[i]); /* Print "(nil)" character by character */
		return (i); /* Return the number of characters printed */
	}
	l = (unsigned long int)pointer; /* Convert pointer to unsigned long int */
	_putchar('0'); /* Print '0' */
	_putchar('x'); /* Print 'x' */
	print_conversion_hexadecimal(l); /* Print hex representation of the pointer */
}
