#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

/* Function Prototypes */

/* Utility functions */
char *get_env_value(char **env, const char *var_name);
int strings_compare(const char *string1, const char *string2);
unsigned int strings_length(const char *string);
char *string_copy(char *destination, const char *source);
char *string_concat(char *destination, const char *source);
int string_to_int(const char *string);

/* Shell functionality */
void execute_command(char **commands, char *shell_name, char **env, int cycle);
void error_message(char *shell_name, int cycle, char *command);
void print_environment(char **env);
int changes_directories(const char *paths);
void child_process(char **cmds, char *shell_name, char **env, int cycle);
char **split_string(char *buffers, const char *delimiter);
void prompt(void);
void signal_handler(int prompt_handle);
void exits_shell(char **commands);
void handles_EOF(char *buff_strings);

/* Memory management */
void free_and_exit(char **cmds);
void memry_freed(char **cmds);

/* Main function */
int main(int num_args, char **arry_args, char **env);

#endif
