#include "main.h"

int main(int ac, char **argv)
{

	char *buffer;
	char *buffer_copy;
	char *token;
	int token_num, i;
	ssize_t characters;

	size_t bufsize = 0;
	token_num = 0;

	(void)ac;

	buffer = NULL;
	buffer_copy = NULL;
	printf("$ ");
	characters = getline(&buffer, &bufsize, stdin);
	/* Allocate memory for the copy */
	buffer_copy = malloc(sizeof(char) * characters);
	if (buffer_copy == NULL)
	{
		return (-1);
	}
	/* Make a copy as the original will be destroyed */
	_strcpy(buffer_copy, buffer);
	if (characters == -1)
	{
		perror("Error");
		return (-1);
	}
	else
	{
		/*Parsing the input*/
		token = strtok(buffer, " ");
		if (token == NULL)
		{
			printf("empty string!");
			return (1);
		}
		/* walk through other tokens */
		while (token != NULL)
		{
			token_num++;
			/* parse the same string again */
			token = strtok(NULL, " ");
		}
		token_num++;

		argv = malloc(sizeof(char *) * token_num);
		token = strtok(buffer_copy, " ");
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
	}
	free(argv);
	free(buffer_copy);
	free(buffer);
	return (0);
}
