#include "main.h"
/*
 * getinput - Function to read line
 * Return: pointer to string (Line)
 */
char *getinput(void)
{
    size_t bufsize;
    char *input;
    bufsize = 0;
    input = NULL;

    /* if get line fails */
    if(getline(&input, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(input);
            exit(EXIT_SUCCESS);
        }
        else
        {
        free(input);
        perror("error ehile reading");
        exit(EXIT_FAILURE);
        }
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
        exit(EXIT_FAILURE);
        /* return NULL; */
    }
    if (command[0])
    {

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
            free(input);
            exit(EXIT_FAILURE);
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
    char *full_path;

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
        full_path = get_cmd(command[0]);
        if(full_path)
        {
        if (execve(full_path, command, env) == -1)
        {
            perror(argv[0]);
            free_grid(command);
            free(full_path);
            exit(1);
        }
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

