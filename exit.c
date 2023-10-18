#include "main.h"
/**
*handle_builtin - function to handle if the command is built ib
*@str: string to be checked
*Return: the function
*/
void (*handle_builtin(char *str))(char **, int status)
{
	sp_t fun_list[] = {
		{"exit", my_exit},
		{"env", my_env},
		{NULL, NULL}};
	int i;

	i = 0;
	while (fun_list[i].command)
	{
		if (_strcmp(fun_list[i].command, str) == 0)
			return (fun_list[i].func);
		i++;
	}
	return (NULL);
}

/**
*my_exit - function to exit from the shell
*@command: the command array
*@status: status
*/
void my_exit(char **command, int status)
{
	free_grid(command);
	exit(status);
}
/**
*my_env - function to print env
*@command: the command array
*@status: status
*/
void my_env(char **command, int status)
{
int i;
(void) status;
i = 0;

while (environ[i])
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
free_grid(command);
/* return (status);*/
}
