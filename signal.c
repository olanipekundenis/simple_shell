#include "shell.h"

/**
 * handler - handles ctrl + c signal
 * @sig: represent signal to handle
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
 * @buf: buffer
 * @args: arguments passed
 * @count: count cmd
 * @av: argument vector
 */

void exxit(char *buf, char **args, int count, char **av)
{
	int status;

	if (args[1] == 0)
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}
	else
	{
		status = _atoi(args[1]);
		if (_isdigit(status) == 1)
		{
			free(buf);
			exit(status);
		}
		else
		exit_errorMessage(args, count, av);
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


