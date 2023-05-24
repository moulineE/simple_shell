#include "shell.h"

int execute(char **argv);
void free_tokens(char **ptr);

/**
 * execute - execute a command with arguments
 * @argv: an array of strings containing the command and its arguments
 *
 * Return: the exit status of the executed command
 */
int execute(char **argv)
{
	pid_t id;
	int status = 0;
	char *path_name = NULL;

	if (argv == NULL || *argv == NULL)
	{
		return (status);
	}
	id = fork();
	if (id < 0)
	{
		_puts("fork");
		return (1);
	}
	if (id == -1)
	{
		_errputs(argv[0]);
		free_tokens(argv);
		free_last_input();
	}
	if (id == 0)
	{
		path_name = NULL;
		if (argv[0][0] == '/' || (argv[0][0] == '.' && argv[0][1] == '/'))
		{
			path_name = argv[0];
		}
		if (path_name == NULL && (argv[0][0] != '/' ||
					(argv[0][0] != '.' && argv[0][1] != '/')))
		{
			path_name = find_path(argv[0]);
		}
		if (execve(path_name, argv, NULL) == -1)
		{
			_errputs(argv[0]);
			free_tokens(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (status);
}

/**
 * free_tokens - frees memory allocated by tokenize()
 * @ptr: pointer to allocated memory
 */
void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
