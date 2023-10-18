#include "main.h"

int (*handle_builtin(char *str))(char **, int status)
{
sp_t fun_list[] = {
{"exit", my_exit},
{NULL, NULL}};
int i;

i = 0;
while (fun_list[i].command)
{
if (_strcmp (fun_list[i].command, str) == 0)
return (fun_list[i].func);
i++; 
}
return (NULL);
}

/* int main()
{
    int (*operation)(char *);

    operation = handle_builtin("exit");
	if (operation != NULL)
	operation("exit");
	else
    printf("fail");
return (0);

}*/

int my_exit(char **command, int status)
{
    free_grid(command);
    exit(status);
}
