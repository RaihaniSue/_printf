#include "mainn.h"

/**
 * print_rot13 - Encodes a string into ROT13.
 * @opaq: A va_list containing the string to convert.
 *
 * Return: The number of characters printed.
 */
int print_rot13(va_list opaq)
{
	int idx_input, idx_output, character_count = 0;
	char *str;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *); /* Extract the string from va_list */
	if (str == NULL) /* Check if the string is NULL */
		str = "(null)"; /* Set the string to "(null)" in this case */

	for (idx_input = 0; str[idx_input] != '\0'; idx_input++)
	{
		for (idx_output = 0; input[idx_output] != '\0'; idx_output++)
		{
			if (str[idx_input] == input[idx_output]) /* if char in input matche */
			{
				_putchar(output[idx_output]); /* Print the corespondin char from output */
				character_count++; /* Increment the character count */
				break; /* Exit the inner loop to continue with the next character */
			}
		}
	}
	return (character_count); /* Return the total number of characters printed */
}
