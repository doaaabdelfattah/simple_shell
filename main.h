#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;

/* String Functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s);
char *_strcat(char *dest, char *src);

/* Helpers function */
void free_grid(char **grid);

char *_getenv(char *name);
char *get_cmd(char *command);

/* Main functions for shell */
char *getinput (void);
char **pars_input(char *input);
void execute(char **command, char **argv, char **env);



#endif
