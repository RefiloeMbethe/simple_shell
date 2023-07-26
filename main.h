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
char **path_direc(char **env);
int strings_compare(const char *string1, const char *string2);
unsigned int strings_length(const char *string);
char *strings_copy(char *desti, const char *sources);
char *string_conc(char *desti, const char *sources);
int string_to_int(const char *string);

/* Shell functionality */
void exe_command(char **commands, char *names, char **env, int cycle);
void error_messages(const char *names, int cycle, char **commands);
void prints_environ(char **env);
int changes_directories(const char *paths);
void child_process(char **cmds, char *names, char **env, int cycle);
char **split_string(char *buffers, const char *delimiter);
void prompt(void);
void signal_handler(int prompt_handle);
void exits_shell(char **commands);
void handles_EOF(char *buff_strings);

/* Memory management */
void free_memry_exit(char **cmds);
void memry_freed(char **cmds);

/* Main function */
int main(int num_args, char **arry_args, char **env);

#endif
