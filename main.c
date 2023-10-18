#include "main.h"
/**
*main - main function
*@ac: arg count
*@argv: argument vector
*@env: environ variable
*Return: 0 on success
*/

int main(int ac, char **argv, char **env)
{
	int status;
	char *input;
	char **command;
	(void)ac;

	input = NULL;
	status = -1;
	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		/* Read input */
		input = getinput();

		if (input == NULL) /* EOF */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			input = NULL;
			free_grid(command);
			return (1);
		}

		/* Parse the input*/
		command = pars_input(input);

		if (command == NULL)
		{
			continue;
		}
		free(input);
		/* Execute the command */
		execute(command, argv, env);
	} while (status == -1);
	return (0);
}

