#include "main.h"

/**
 * size_to_argument - entrypoint
 * @f: format args
 * @i: args to be printed
 *
 * Return: Precision.
 */
int size_to_argument(const char *f, int *i)
{
	/*Initialize a variable to point to the next character in the format string*/
	int flag_i = *i + 1;
	int s = 0; /*Initialize the size specifier to zero*/

	/*Check if the next character is 'l', indicating a long size specifier*/
	if (f[flag_i] == 'l')
		s = S_LONG;
	/*Check if the next character is 'h', indicating a short size specifier*/
	else if (f[flag_i] == 'h')
		s = S_SHORT;

	/*If no size specifier is found, set pos point to current char*/
	if (s == 0)
		*i = flag_i - 1;
	/*If a size specifier is found, update pos point to the nxt char*/
	else
		*i = flag_i;

	return (size);
}
