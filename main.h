#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
struct stat st;
extern char **environ;
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(char *env);
char *_strdup(char *str);
char *_which(char *cmd);
int _execve(char **args);
char *_strchr(char *s, char c);
char **generate_arguments(char *s, char *delimeters);
void _print_env(void);
void free_array(char **array);
void _perror(char *name, char *cmd);
#endif
