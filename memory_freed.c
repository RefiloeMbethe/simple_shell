#include "main.h"

/**
 * free_and_exit - Free all the memory allocated for command and exit the program.
 * @cmds: Pointer to allocated memory.
 * Return: Nothing.
 */
void free_and_exit(char **cmds)
{
    if (cmds == NULL)
        return;

    for (size_t i = 0; cmds[i]; i++)
    {
        free(cmds[i]);
    }

    free(cmds);
    exit(0);
}
