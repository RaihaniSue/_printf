#include "main.h"

/**
 * print_binary_unsigned - Entry point
 * @opaq : the parameters
 *
 * Return: the number of characters printed
 */
int print_binary_unsigned(va_list opaq)
{
	int num = va_arg(b, unsigned int); /* Extract the unsigned integer argument */
	int count = 0; /* Initialize the character count */
	int is_digit_printed = 0; /* Initialize a flag for tracking printed digits */

	if (num == 0) /* Check if the number is zero */
	{
		_putchar('0'); /* Print '0' */
		return (1); /* Return 1 character printed */
	}

	while (num > 0) /* Continue until the number becomes zero */
	{
		int digit = num % 2;/* Calculate the least significant binary digit */

		num = num / 2; /* Shift the number right by one bit */

		/* Check if the digit is non-zero or a digit has been printed before */
		if (digit || is_digit_printed)
		{
			_putchar(digit + '0'); /* Print the binary digit */
			count++; /* Increment the character count */
			is_digit_printed = 1; /* Set flag to indicate a digit been printed */
		}
	}

	return (count); /* Return the total number of characters printed */
}
