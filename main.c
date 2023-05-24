#include"shell.h"
#include<string.h>

int main(void);
void _cd(char **av);
void env(void);

/**
 * main - simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	int status, i, flag = 0;
	char *cmd;
	char **args;

	do {
		cmd = get_input();
		if (cmd == NULL)
		{
			break;
		}
		if (cmd[0] == ' ')
		{
			flag = 1;
			for (i = 0; cmd[i]; i++)
			{
				if (!((cmd[i]) == ' '))
				{
					flag = 0;
				}
			}
		}
		if (flag == 1)
		{
			flag = 0;
			free(cmd);
			continue;
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
		if (_strcmp(args[0], "env") == 0)
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
/**
 * _cd - change the current directory and update $PWD and $OLDPWD
 * @av: the tokenized entry with the new directory
 */
void _cd(char **av)
{
	int ret;
	char *dir = av[1], buff[4096];

	getcwd(buff, 4096);
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd : no home directory found\n");
			return;
		}
		else
		{
			_puts(dir);
		}
	}
	if (dir[0] == '-' && dir[1] == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			perror("cd: OLDPWD not set");
		}
		else
		{
			_puts(dir);
		}
	}
	ret = chdir(dir);

	 /**
	  * waiting for _setenv devlopment
	  * if (ret =! -1)
	  * {
	  * _setenv(OLDPWD, buff, 1);
	  * _setenv(PWD, dir, 1);
	  * }
	  */
	if (ret == -1)
	{
		perror("cd");
	}
}
/**
 * env - print the env
 */
void env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
