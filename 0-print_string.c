#include "main.h"
/**
 * print_percent - Entry point
 * @opaq : the argumets in va_list
 *
 * Return: the length of the strings
 */
int print_percent(va_list opaq)
{
	char *s; /*intentions to store string */
	int x; /* int for loop counting*/
	int l; /*storing the length of the string*/

	str = va_arg(opaq, char*); /*extracton from va_list*/
	if (s == NULL) /*checking if string is null*/
	{
		s = "(null)"; /* if yes then setting s to null*/
		l = _strlen(s); /*calculate the length*/
		for (x = 0; x < l; x++) /*looping through the characters*/
			_putchar(s[x]);
		return (l);
	}
	else
	{
		l = _strlen(s);
		for (x = 0; x < l; x++)
			_putchar(s[x]);
		return (l);
	}
}
