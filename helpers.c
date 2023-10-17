#include "main.h"
/*
 * getinput - Function to read line
 * Return: pointer to string (Line)
 */
char *getinput(void)
{
    ssize_t characters;
    size_t bufsize;
    char *input;
    bufsize = 0;
    input = NULL;

    characters = getline(&input, &bufsize, stdin);
    if (characters == -1)
    {
        free(input);
        return (NULL);
    }
    return (input);
}

/*
 * pars_input - split input aand save it in array
 *@input: pointer to string (input)
 * Return: pointer to array pointer
 */

char **pars_input(char *input)
{
    int i, j;
    char *input_copy;
    char *token;
    size_t counter;
    char **command;
    i = 0;

    input_copy = _strdup(input);
    if (input_copy == NULL)
        return NULL;

    /* Parsing the copy to know words count*/
    counter = 0;
    token = strtok(input_copy, " \n\t");
    if (token == NULL)
    {
        free(input_copy);
        return NULL;     
    }
    /* Calculate input words (tokens) */
    while (token)
    {
        counter++;
        /* parse the same string again */
        token = strtok(NULL, " \n\t");
    }
    free(input_copy);
    input_copy = NULL;

    command = malloc(sizeof(char *) * (counter + 1));
    if (command == NULL)
    {
        free(input);
        return NULL;
    }
    /* Parsing the input and store them in array */
    token = strtok(input, " \n\t");
    while (token)
    {
        command[i] = malloc(sizeof(char) * (_strlen(token) + 1));
        if (command[i] == NULL)
        {
            for(j = 0; j < i; j++)
            {
                free(command[j]);
            }
            free(command);
             return NULL;
        }
        _strcpy(command[i], token);
        i++;
        token = strtok(NULL, " \n\t");
    }
    command[counter] = NULL;

    return (command);
}


/*
* execute - exectute the program
*
*/

void execute(char **command, char **argv, char **env)
{
    pid_t fork_value, wait_value;
    int status;


    fork_value = fork();
    /* if fork fails */
    if (fork_value == -1)
    {
        perror(argv[0]);
        free_grid(command);
        exit(1);
    }
    /* on child process */
    if (fork_value == 0)
    {
    if (execve(command[0], command, env) == -1)
        {
            perror(argv[0]);
            free_grid(command);
            exit(1);
        }
    }
    /* on parent process */
    else
    {
        wait_value = wait(&status);
        if (wait_value == -1)
        {
            perror("wait error");
        }
        free_grid(command);
    }

}

