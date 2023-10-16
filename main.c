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
			exit(1);
		}

		/* Parse the input*/
		command = pars_input(input);
		if (command == NULL)
			continue;

		/* Execute the command */
		execute(command, argv, env);
	}

	free(input);
	free_grid(command);
	return (0);
}
