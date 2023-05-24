#include "shell.h"

/**
 * _getenv - This function is used to get the part of
 * an environ
 * @name: env to search
 * Return: a pointer to environ
 */

char *_getenv(const char *name)
{
	int comp;
	char **envir;
	char *value;
	size_t len;

	if (name == NULL)
		return (NULL);

	len = _count(name);

	for (envir = environ; *envir != NULL; ++envir)
	{
		comp = _strncmp(*envir, name, len);
	if (comp == 0 && (*envir)[len] == '=')
	{
		value = malloc(_strlen(*envir) - len);
		if (value == NULL)
			return (NULL);

		_strcpy(value, *envir + len + 1);
		return (value);
	}
	}
		return (NULL);
}

/**
 * printenv - This function prints env variables
 */

void printenv(void)
{
	int i = 0, len;

	while (environ[i] != NULL)
	{
	len = _strlen(environ[i]);
	write(STDOUT_FILENO, environ[i], len);
		_putchar('\n');
		++i;
	}
}

/**
 * *_strcpy - The function copies an input from a string
 * to another
 * @dest: destination of copied str
 * @src: source to copy
 * Return: Str (success)
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}

	j = 0;

	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
		dest[j] = '\0';
		return (dest);
}
/**
 * _count - function to count a str
 * @s: str to count
 * Return: len of str (success)
 */

size_t _count(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
