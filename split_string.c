#include "main.h"

/**
 * split_string - Split the input buffer into an array of strings using the specified delimiter.
 *
 * @buffers: Pointer to the input string to be split.
 * @delimiter: Delimiter used for splitting the string.
 *
 * Return: Pointer to a dynamically allocated array of strings (tokens) on success,
 *         or NULL on failure.
 */
char **split_string(char *buffers, const char *delimiter)
{
    if (buffers == NULL)
        return NULL;

    size_t bufferSizes = strlen(buffers);
    char **tokens_array = malloc((bufferSizes + 1) * sizeof(char *));
    if (tokens_array == NULL)
    {
        perror("Memory allocation error");
        free(buffers);
        memry_freed(tokens_array);
        exit(EXIT_FAILURE);
    }

    char *token = strtok(buffers, delimiter);
    int token_count = 0;

    while (token != NULL)
    {
        tokens_array[token_count] = strdup(token);
        if (tokens_array[token_count] == NULL)
        {
            perror("Memory allocation error");
            memry_freed(tokens_array);
            return NULL;
        }
        token = strtok(NULL, delimiter);
        token_count++;
    }

    tokens_array[token_count] = NULL;
    return tokens_array;
}
