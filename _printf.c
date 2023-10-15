#include "main.h"

/**
 * find_function - associated printing f for a format specifier.
 * @format: The format specifier string.
 *
 * Return: The associated printing function or NULL if not found.
 */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	format_specifier_t format_specifiers[] = {
		{"%c", print_char},
		{"%%", print_percent}, /* Handle the literal '%' */
		{"%s", print_string},
		{"%i", print_int},
		{"%d", print_dec},
		{"%r", print_rev},
		{"%b", print_binary_unsigned},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"%p", print_b_address},
		{"%R", print_rot13},
		{NULL, NULL}
	};

	while (format_specifiers[i].specifier)
	{
		if (format_specifiers[i].specifier[0] == format[0])
			return (format_specifiers[i].function); /* Return the associated function */
		i++;
	}

	return (NULL); /* Return NULL if no match is found */
}

/**
 * _printf - Produce output according to a format string.
 * @format: The format string with format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*print_function)(va_list);
	unsigned int i = 0, char_count = 0;

	if (format == NULL)
		return (-1); /* Return -1 for invalid input */

	va_start(args, format); /* Initialize the va_list with the arguments */

	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			char_count++;
			i++;
		}
		if (format[i] == '\0')
			return (char_count); /* char count if the end of format is reached */
		print_function = find_function(&format[i + 1]);

		if (print_function != NULL)
		{
			char_count += print_function(args); /* Call the associated f*/
			i += 2; /* Skip the format specifier */
			continue;
		}
		if (!format[i + 1])
			return (-1); /* Return -1 for an invalid format specifier */
		_putchar(format[i]); /* Print the character */
		char_count++;

		if (format[i + 1] == '%')
			i += 2; /* Skip double '%' */
		else
			i++; /* Move to the next character in the format string */
	}
	va_end(args); /* Clean up the va_list */
	return (char_count); /* Return the total character count printed */
}
