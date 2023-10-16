#include "main.h"

int main(int ac, char **argv, char **env)
{
	char *input;
	char **command;
	(void)ac;
	input = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		/* Read input */
		input = getinput();

		if (input == NULL) /* EOF */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			free_grid(command);
			exit(1);
		}

		/* Parse the input*/
		command = pars_input(input);
		if (command == NULL)
			{
				free(input);
				continue;
			}
		free(input);
		/* Execute the command */
		execute(command, argv, env);
	}
}
