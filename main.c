#include "main.h"

/**
 * main - Main shell loop.
 * @num_args: Number of inputed args.
 * @arry_args: Pointer to array of inputed args.
 * @env: Pointer to array of env variables.
 * Return: 0.
 */
int main(int num_args, char **arry_args, char **env)
{
    char *buff = NULL, **commands = NULL;
    size_t buffersize = 0;
    ssize_t chars_reading = 0;
    int cycle = 0;

    (void)num_args;

    while (1)
    {
        cycle++;
        signal(SIGINT, signal_handler);
        prompt();

        chars_reading = getline(&buff, &buffersize, stdin);
        if (chars_reading == -1)
            handles_EOF(buff);
        else if (*buff != '\n')
        {
            buff[chars_reading - 1] = '\0';
            commands = split_string(buff, " \0");
            free(buff);

            if (commands[0] != NULL)
            {
                if (strings_compare(commands[0], "exit") == 0)
                {
                    exits_shell(commands);
                }
                else if (strings_compare(commands[0], "cd") == 0)
                {
                    changes_directories(commands[1]);
                }
                else
                {
                    child_process(commands, arry_args[0], env, cycle);
                }
            }
            memry_freed(commands);
        }
    }

    return (EXIT_FAILURE); // The loop is infinite, so it will never reach this point.
}
