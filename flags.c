#include "main.h"

/**
 * flag_handler - Entry point
 * @f: flagging
 * @i:  parameter.
 * Return: spec_flag:
 */
int flag_handler(const char *f, int *i)
{
	int j, a;
	int spec_flag = 0;
	const char spec_flag_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int spec_flag_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	/*Check if the current char in the format str is a recognized flag*/
	for (a = *i + 1; f[a] != '\0'; a++)
	{
		for (j = 0; spec_flag_CH[j] != '\0'; j++)
			if (f[a] == spec_flag_CH[j])
			{
				/*Set the corresponding flag bit*/
				spec_flag |= spec_flag_ARR[j];
				break;
			}

		/*If the current char is not a recognized flag, exit the loop*/
		if (spec_flag_CH[j] == 0)
			break;
	}

	/*Update the position pointer to the last checked characte*/
	*i = a - 1;

	return (spec_flag);
}
