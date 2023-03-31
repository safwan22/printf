#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, c_i;
	int flags = 0;
	const char FLAGS_CHA[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_i = *i + 1; format[c_i] != '\0'; c_i++)
	{
		for (j = 0; FLAGS_CHA[j] != '\0'; j++)
			if (format[c_i] == FLAGS_CHA[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CHA[j] == 0)
			break;
	}

	*i = c_i - 1;

	return (flags);
}

