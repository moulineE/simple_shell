#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

char *get_input(void);
void _puts(char *str);
void prompt(void);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(const char *s);
void free_tokens(char **ptr);
char **_strtok(char *cmd, const char *delim);
char **tokenize(char *cmd);
void free_last_input(void);
int execute(char **argv);
char *find_path(char *av);
void _cd(char **av);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_path(void);
char *_getenv(const char *name);
extern char **environ;
char *_strcat(char *dest, const char *src);
char *add_end(char *dest, const char *cmd);
void env(void);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif
