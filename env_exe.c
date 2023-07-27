#include "main.h"

/**
 * get_env_value - Get the value of a specific environment variable.
 *
 * @env: Pointer to the environmental variables array.
 * @var_name: Name of the environment variable to find.
 *
 * Return: Pointer to value of the environment variable, or NULL if not found.
 */
char *get_env_value(char **env, const char *var_name)
{
	while (*env)
	{
		if (strings_compare(*env, var_name) == 0)
		{
			char *value = *env + strings_length(var_name) + 1;
			return value;
		}
		env++;
	}
	return NULL;
}

/**
 * execute_command - Function that executes a command.
 *
 * @commands: Pointer to the command strings array.
 * @shell_name: Name of the shell.
 * @env: Pointer to the environmental variables array.
 * @cycle: Number of executed cycles.
 *
 * Return: Nothing.
 */
void execute_command(char **commands, char *shell_name, char **env, int cycle)
{
	char **path_dirs = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (strings_compare(commands[0], "env") == 0)
	{
		prints_environ(env);
		return;
	}

	if (stat(commands[0], &st) == 0)
	{
		if (execve(commands[0], commands, env) < 0)
		{
			perror(shell_name);
			free_memry_exit(commands);
		}
	}
	else
	{
		path_dirs = split_string(get_env_value(env, "PATH"), ":");
		while (path_dirs[i])
		{
			full_path = string_conc(path_dirs[i], "/");
			full_path = string_conc(full_path, commands[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, commands, env) < 0)
				{
					perror(shell_name);
					free_memry_exit(commands);
				}
				return;
			}
			free(full_path);
		}
	}

	error_message(shell_name, cycle, commands[0]);
	free_memry_exit(commands);
}

/**
 * error_message - Print the command not found error message.
 *
 * @shell_name: Name of the shell.
 * @cycle: Number of cycles.
 * @command: Name of the command.
 *
 * Return: Nothing.
 */
void error_message(char *shell_name, int cycle, char *command)
{
	char cycle_char = cycle + '0';
	write(STDOUT_FILENO, shell_name, strings_length(shell_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cycle_char, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command, strings_length(command));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * print_environment - Print all environmental variables.
 *
 * @env: Pointer to the environmental variables array.
 *
 * Return: Nothing.
 */
void print_environment(char **env)
{
	while (*env)
	{
		write(STDOUT_FILENO, *env, strings_length(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
#include "main.h"

/**
 * get_env_value - Get the value of a specific environment variable.
 * ...
 * (rest of the function remains unchanged)
 */

/**
 * execute_command - Function that executes a command.
 * ...
 * (rest of the function remains unchanged)
 */

/**
 * error_message - Print the command not found error message.
 * ...
 * (rest of the function remains unchanged)
 */

/**
 * print_environment - Print all environmental variables.
 * ...
 * (rest of the function remains unchanged)
 */

/* Rest of the functions remain unchanged */
