#include "main.h"

/**
 * print_unsigned_int - Entry point one
 * @opaq: List a of arguments
 * @b: array
 * @f:  flag
 * @w: width
 * @prec: precision
 * @size: Size specifier
 * Return: printed chars
 */
int print_unsigned_int(va_list opaq, char b[],
	int f, int w, int prec, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(opaq, unsigned long int);

	/*convert the number based on size*/
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	/*convert number to a string in reverse order*/
	while (number > 0)
	{
		b[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	/*Call a function to write the result with flags, width, and precision*/
	return (write_unsgnd(0, i, b, f, w, prec, size));
}

/**
 * print_octal - Entry point two
 * @opaq: arguments
 * @b: array
 * @f:  flag
 * @w: width
 * @prec: precision
 * @size: Size specifier
 * Return: printed chars
 */
int print_octal(va_list opaq, char b[],
	int f, int w, int prec, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(opaq, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(w);

	/*Convert the number based on the size specifier*/
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	/*Convert the number to an octal string in reverse order*/
	while (number > 0)
	{
		b[i--] = (number % 8) + '0';
		number /= 8;
	}

	/*Add '0' prefix if the '#' flag is set and the number is not zero*/
	if (f & F_HASH && init_number != 0)
		b[i--] = '0';

	i++;

	return (write_unsgnd(0, i, b, f, w, prec, size));
}

/**
 * print_hexdecimal - entry point three
 * @opaq: args
 * @b: array
 * @f:  flag
 * @w: width
 * @prec: precision
 * @size: Size specifier
 * Return: printed chars
 */
int print_hexdecimal(va_list opaq, char b[],
	int f, int w, int prec, int size)
{
	return (print_hex(opaq, "0123456789abcdef", b,
		f, 'x', w, prec, size));
}

/**
 * print_hex_upper - Prints an unsigned numberber in upper hexadecimal notation
 * @opaq: Lista of arguments
 * @b: b array to handle print
 * @f:  flag
 * @w: width
 * @prec: precision
 * @size: Size specifier
 * Return: printed chars
 */
int print_hex_upper(va_list opaq, char b[],
	int f, int w, int prec, int size)
{
	return (print_hex(opaq, "0123456789ABCDEF", b,
		f, 'X', w, prec, size));
}

/**
 * print_hex - Prints a hexadecimal numberber in lower or upper
 * @opaq: Lista of arguments
 * @ar_map: Array of values to map the numberber to
 * @b: b array to handle print
 * @f:  flag
 * @act_f: flag
 * @w: width
 * @prec: precision
 * @size: Size specifier
 * @size: Size specification
 * Return: printed chars
 */
int print_hex(va_list opaq, char ar_map[], char b[],
	int f, char act_f, int w, int prec, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(opaq, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(w);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		b[i--] = ar_map[number % 16];
		number /= 16;
	}

	if (f & F_HASH && init_number != 0)
	{
		b[i--] = act_f;
		b[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, b, f, w, prec, size));
}


