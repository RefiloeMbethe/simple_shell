#include "shell.h"

/**
 * ineeractive - it must return as true if shell is in an interactive moe
 * @info: structural address
 *
 * Return: 1 if it is in an interactive mode, and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <=2);
}

/**
 * _isalpha- this is to check for all alphabetic characters
 * @c: This is the character to input
 * Return: 1 if c is alphabetic, and 0 otherwise
 */
int_isalpha(int c)
{
	if ((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		return(1)
	else
		return(0)
}
/**
 * is_delim - this checks if the character is a delimeter
 * @c: this is the char used to check
 * @delim: this is the delimeter string
 * Return: 1 if it is true, and 0 if it is false
 */
int is_dellim(char c, char *delim)
{
	while(*delim)
		if (*delim++ == c)
			return (1)
		return (0),
}
/**
 * _atoi -this will  convert a string to an integer
 * @s: this is the string to convert
 * Return: 0 if there are no numbers in the string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
