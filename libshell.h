#ifndef LIBSHELL_H
#define LIBSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define INITIAL_BUFFER_SIZE 1024

extern char **environ;

/** std_main_functions.c **/
int _putchar(char c);
int _putstr(const char *str);
size_t _strlen(const char *str);
char* _strtok(char* string, const char* delim);


/** std_other_functions.c **/
char *_strdup(const char *src);
void _strcpy(char *dest, const char *src);
char* _strcat(char *dest, const char *src);
int _atoi(const char *s);
int _strcmp(const char *s1, const char *s2);


/** sys_main_functions.c **/
int execute_with_path(char* tokens[]);
int execute_without_path(char* command, char* tokens[]);
ssize_t _getline(char **lineptr, size_t *n);
char *_getenv(const char *input);

/** sys_other_functions.c **/
void print_environment(void);
void exit_shell(void);

/** command_handler.c **/
void command_handler(int token_count, char* tokens[]);


/** Exec_functions.c **/
char *find_executable(const char *command);
void execute_command(const char *command_path, char *tokens[]);
int tokenize_command(char *command_line, char *tokens[]);


#endif
