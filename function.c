#include "main.h"

/**
 * are_strings_equal - Checks if two strings are equal.
 *
 * @string1: Pointer to the first string.
 * @string2: Pointer to the second string.
 *
 * Return: 1 if equal, 0 otherwise.
 */
int are_strings_equal(const char *string1, const char *string2)
{
    while (*string1 && *string2)
    {
        if (*string1 != *string2)
            return 0;

        string1++;
        string2++;
    }

    return (*string1 == *string2);
}

/**
 * string_length - Calculates the length of a string.
 *
 * @string: Pointer to the input string.
 *
 * Return: Length of the string.
 */
unsigned int string_length(const char *string)
{
    unsigned int length = 0;

    while (*string)
    {
        length++;
        string++;
    }

    return length;
}

/**
 * string_copy - Copies a string to a destination buffer.
 *
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *string_copy(char *destination, const char *source)
{
    char *temp = destination;

    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return temp;
}

/**
 * string_concatenate - Concatenates two strings with a '/' in between.
 *
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *string_concatenate(char *destination, const char *source)
{
    char *temp = destination;

    while (*destination)
        destination++;

    *destination = '/';
    destination++;

    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return temp;
}

/**
 * string_to_int - Converts a string to an integer.
 *
 * @string: Pointer to the input string.
 *
 * Return: The integer equivalent of the string.
 */
int string_to_int(const char *string)
{
    int sign = 1, state = 0, output = 0;

    while (*string)
    {
        if (*string == '-')
            sign *= -1;

        if (*string >= '0' && *string <= '9')
        {
            state = 1;
            output *= 10;
            output += (*string - '0');
        }
        else if (state == 1)
            break;

        string++;
    }

    return (sign * output);
}
