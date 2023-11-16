#include "shell.h"

/**
 * my_strcmp - compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if equal, 1 if str1>str2 and -1 if str1<str2
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}
	else
	{
		return ((*str1 == '\0') ? -1 : 1);
	}
}
