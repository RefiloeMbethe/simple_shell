#include "main.h"

/**
 * changes_directories - Function that changes the working directory.
 *
 * @paths: The new current working directory. If NULL, the function will
 *         set the working directory to the current process's current working directory.
 *
 * Return: 0 on success, -1 on failure.
 */
int changes_directories(const char *paths)
{
	if (paths == NULL)
	{
		char buffer[1024];
		paths = getcwd(buffer, sizeof(buffer));
		if (paths == NULL)
		{
			perror("getcwd");
			return (-1);
		}
	}

	if (chdir(paths) == -1)
	{
		perror("chdir");
		return (-1);
	}

	return (0);
}

/**
 * child_process - Function that creates a sub-process to execute a command.
 *
 * @cmds: Pointer to the tokenized command.
 * @names: Pointer to the shell name.
 * @env: Pointer to the environment variable pointers.
 * @cycle: Number of executed cycles.
 *
 * Return: Nothing.
 */
void child_process(char **cmds, char *names, char **env, int cycle)
{
	int pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free_memry_exit(cmds);
	}
	else if (pid == 0)
	{
		execute_cmd(cmds, names, env, cycle);
		memry_freed(cmds);
	}
	else
	{
		int status;
		int waitingResults = waitpid(pid, &status, 0);
		if (waitingResults < 0)
		{
			perror("waitpid");
			free_memry_exit(cmds);
		}
		memry_freed(cmds);
	}
}
