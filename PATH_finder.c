#include "shell.h"

char *get_path(void);
char *_getenv(const char *name);

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: the value of $PATH.
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
