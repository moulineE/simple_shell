#include"shell.h"
#include<string.h>
/**
 * main - simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	int status;
	char *cmd;
	char **args;

	do {
		cmd = get_input();
		if (cmd == NULL)
		{
			break;
		}
		args = tokenize(cmd);
		if (args == NULL)
		{
			free(cmd);
			free_tokens(args);
			continue;
		}
		if (_strcmp(args[0], "exit") == 0)
		{
			free_tokens(args);
			free(cmd);
			exit(0);
		}
		if (_strcmp(args[0], "cd") == 0)
		{
			_cd(args);
			free_tokens(args);
			args = NULL;
			continue;
		}
		if (strcmp(args[0], "env") == 0)
		{
			env();
			continue;
		}
		status = execute(args);
		free(cmd);
		free_tokens(args);
		status = 1;
		} while (status);
		return (EXIT_SUCCESS);
}
