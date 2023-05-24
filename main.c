#include "shell.h"

/**
 * main - SIMPLE SHELL
 * @ac: argument count
 * @av: argument vector
 * Return: returns 0 success
 */

int main(int __attribute__ ((unused)) ac, char **av)
{
	ssize_t read;
	size_t size = 0;
	int count = 0;
	char *buf = NULL;

	signal(SIGINT, handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, PROMPT, 5);
			fflush(stdout);
		}
		read = getline(&buf, &size, stdin);
		if (read == -1)
		{
			break;
		}
			count++;
			removechar(buf, '\n');
		if (_strlen(buf) == 0)
			continue;
		if (_strcmp(ENVV, buf) == 0)
		{
			printenv();
			continue;
		}
		analyze(buf, count, av);
			size = 0;
			free(buf);
			buf = NULL;
	}
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
		}

		free(buf);
		return (EXIT_SUCCESS);
}
