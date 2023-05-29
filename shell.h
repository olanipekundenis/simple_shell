#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define EXXIT "exit"
#define ENVV "env"
#define MAX 20
#define MAX_PATH 1024
#define PROMPT "($) "

void analyze(char *buf, int count, char **av);
int write_error(char error);
void error_message(char **args, int count, char **av);
void getpath(char **args, int count, char **av);
int _putchar(char c);
void printenv(void);
void exxit(char *buf, char **args, int count, char **av);
void removechar(char *str, char c);
int spacehandler(char *buf);
int _isdigit(int c);
void exit_errorMessage(char **args, int count, char **av);
char *path_concat(char *token, char *arg);
int _atoi(char *s);
size_t _count(const char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void execute(char *path, char **args);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strlen(char *s);
void handler(int sig);
#endif
