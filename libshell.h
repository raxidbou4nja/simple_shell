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





#endif
