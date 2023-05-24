#include "shell.h"
char *get_path(void);
char *_getenv(const char *name);
char *find_path(char *cmd);
char *add_end(char *dest, const char *cmd);
/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: (Success)the value of $PATH.
 */
char *get_path(void)
{
	return (_getenv("PATH"));
}

/**
 * _getenv - get the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}
	return (NULL);
}

/**
 * find_path - find the path of an exe
 * @cmd: the exe to find
 *
 * Return: the path of cmd, or NULL if doesnt exist
 */
char *find_path(char *cmd)
{
	char *path, **dir, buffer[4096], *cmd_path;
	int stat_ret, i = 0, j = 0;
	struct stat st;

	path = get_path();
	if (path == NULL)
	{
		return (NULL);
	}
	dir = _strtok(path, ":");
	if (dir == NULL)
	{
		return (NULL);
	}
	for (i = 0; dir[i]; i++)
	{
		for (j = 0; j < 4096; j++)
		{
			buffer[j] = 0;
			_strcpy(buffer, dir[i]);
			add_end(buffer, cmd);
			stat_ret = stat(buffer, &st);
			if (stat_ret == 0)
			{
				free_tokens(dir);
				cmd_path = malloc(sizeof(char) * (_strlen(buffer) + 1));
				if (cmd_path == NULL)
				{
					return (NULL);
				}
				_strcpy(cmd_path, buffer);
				return (cmd_path);
			}
		}
	}
	if (stat_ret == -1)
	{
		free_tokens(dir);
	}
	return (NULL);
}

/**
 * add_end - add the cmd exe at the end of the path
 * @dest: the path
 * @cmd: the exe
 *
 * Return: the exe with it path
 */
char *add_end(char *dest, const char *cmd)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	*dest++ = '/';
	while (*cmd)
	{
		*dest++ = *cmd++;
	}
	*dest = '\0';
	return (ret);
}
