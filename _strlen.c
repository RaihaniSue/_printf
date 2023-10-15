#include "main.h"
#include <stdio.h>
/**
 * _strlen - Entry point
 * @s: the given parameter
 * Return:the length of the given parameter
 */
int _strlen(char *s)
{
	int x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
