#include "shell.h"

/**
 * analyze - This function runs thorough checks on
 * command input on the buffer
 * @buf: buffer
 * @count: count inputs
 * @av: argument vector
 */

void analyze(char *buf, int count, char **av)
{
	char *args[MAX];
	char *token;
	int i = 0;

	token = strtok(buf, " ");
	while (token != NULL && i < MAX - 1)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		++i;
	}
		args[i] = NULL;
		if (_strncmp(EXXIT, args[0], 4) == 0)
		{
			exxit(args[1]);
		}
		else if (access(args[0], X_OK) == 0)
		{
			execute(args[0], args);
		}
		else
		getpath(args, count, av);
}

/**
 * getpath - This function searches if a command exist
 * and gets the path
 * @args: arguments to check
 * @count: count commands
 * @av: argument vector
 */

void getpath(char **args, int count, char **av)
{
	char *path = _getenv("PATH"), *token;
	char *paths;
	int found = 0;

		if (path == NULL)
		{
			exit(EXIT_FAILURE);
		}

	removechar(path, '\n');
	token = strtok(path, ":");
	while (token != NULL)
	{
		paths = path_concat(token, args[0]);

		if (access(paths, X_OK) == 0)
		{
			found = 1;
			execute(paths, args);
			free(paths);
			break;
		}
			free(paths);
			token = strtok(NULL, ":");
	}
		free(path);
	if (found == 0)
	{
		error_message(args, count, av);
	}
}


/**
 * path_concat - This function concats token and a path
 * @token: path
 * @arg: argumeent passed
 * Return: pointer to str
 */

char *path_concat(char *token, char *arg)
{
	char *ptr;
	int len1, len2;

	if (!token || !arg)
		return (NULL);

	len1 = _strlen(token);
	len2 = _strlen(arg);

	ptr = malloc(sizeof(char) * len1 + 2 + len2);
	if (!ptr)
		return (NULL);

	_strcpy(ptr, token);
	_strcat(ptr, "/");
	_strcat(ptr, arg);

	return (ptr);
}
