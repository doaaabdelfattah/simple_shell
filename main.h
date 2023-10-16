#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int myprint(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid);

char *getinput (void);
char **pars_input(char *input);
void execute(char **command, char **argv, char **env);



#endif
