#include "shell.h"

/**
 * handler - handles ctrl + c signal
 * @sig: signal to handle
 */

void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
	fflush(stdout);
}

/**
 * removechar - This function removes a char
 * @str: str
 * @c: char to remove
 */

void removechar(char *str, char c)
{
	int len = strlen(str);
	int i, j;

	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] != c)
		{
		str[j] = str[i];
			j++;
		}
	}
		str[j] = '\0';
}

/**
 * exxit - function to track exit status
 * @args: arguments passed
 */

void exxit(char *args)
{
	int status;

	if (args == 0)
		exit(EXIT_SUCCESS);
	else
	{
		status = _atoi(args);
		exit(status);
	}
}

/**
 * _atoi - This function converts a str to number
 * @s: string to convert
 * Return: int (success)
 */

int _atoi(char *s)
{
	int i = 0, convert = 1, j = 0;
	unsigned int result = 0;

	while (s[i])
	{
	if (s[i] == '-')
	{
		convert *= -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		j = 1;
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	if (j == 1)
	{
		break;
	}

		i++;
	}
		result *= convert;
		return (result);
}
