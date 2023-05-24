#include "shell.h"

/**
 * execute - This function exxecutes a command
 * @path: path of command passed
 * @args: argument passed
 */

void execute(char *path, char **args)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(path, args, environ);
		perror("exec: error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

/**
 * error_message - This function displays error essage
 * if command isn't able to run
 * @args: argument passed
 * @count: count commands
 * @av: argument vector
 */

void error_message(char **args, int count, char **av)
{
	int temp, mult = 1, len = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);

	temp = count;

	while (temp >= 10)
	{
		temp /= 10;
		mult *= 10;
		++len;
	}
	while (len > 1)
	{
		if ((count / mult) < 1)
		{
			write_error((count / mult + '0'));
		}
		else
			write_error((count / mult) % 10);
		--len;
		mult /= 10;
	}
		write_error(count % 10 + '0');
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);

}

/**
 * write_error - This function converts int to char
 * @error: char to right
 * Return: int (success)
 */

int write_error(char error)
{
	return (write(STDERR_FILENO, &error, 1));
}
