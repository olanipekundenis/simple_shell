#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - This function dispalys the length of
 * a string
 * @s: parameter given
 * Return: length;
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strncmp - This function compares str according to n number
 * of bytes
 * @str1: string one
 * @str2: str 2
 * @n: number of str to compare
 * Return: 0, > 0 or < 0
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL || str2 == NULL || n == 0)
		return (0);

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}

		if (str1[i] == '\0')
			return (0);
	}
		return (0);
}

/**
 * _strcmp - This function compares two str
 * @s1: first str
 * @s2: second str
 * Return: differnce (success)
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
		i++;
	}
		return (s1[i] - s2[i]);
}

/**
 * _strcat - This function concatenates two pointer arguments
 * @dest: destination the concated strings
 * @src: parameter source to be added to dest
 * Return: char
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		j++;
	}
		dest[i] = '\0';

		return (dest);
}

