#include "main.h"

/**
 * print_conversion_hexadecimal - Prints an unsigned long int in hex
 * @n: The unsigned long int to be printed.
 *
 * Description: Prints an unsigned long int in hex format using _putchar.
 *
 * Return: The number of characters printed.
 */
int print_conversion_hexadecimal(unsigned long int n)
{
	unsigned long int len, base, j, digit, num;
	int count = 0;
	char hex_diff;

	if (n != 0) /* Check if the input number is not zero */
	{
		num = n;
		len = 0;
		hex_diff = 'A' - ':'; /* Calculate the dif in uppercase and ':' */
		while (num != 0)
		{
			num /= 16; /* Div num by 16 to calc its length */
			len++;
		}
		base = 1;
		for (j = 1; j <= len - 1; j++)
			base *= 16; /* Calc the base (16^x) for the conversion */
		for (j = 1; j <= len; j++)
		{
			digit = n / base; /* Calc the current hex digit */
			if (digit < 10)
				_putchar(digit + '0'); /* Print the digit if is < than 10 */
			else
				_putchar(digit + '0' + hex_diff); /* Print in uppercase */
			count++; /* Increment the character count */
			n -= digit * base; /* Update the remaining number */
			base /= 16; /* Reduce the base for the next digit */
		}
	}
	else
	{
		_putchar('0'); /* Print '0' if the input number is 0 */
		return (1); /* Return 1 character printed */
	}
	return (count); /* Return the total number of characters printed */
}
