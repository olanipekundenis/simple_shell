#include "shell.h"

/**
 * Description: _isdigit - This function returns 1 and 0
 * if an argument is a number or not
 * @c: parameter passed to function
 * Return: 1 0r 0
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}
