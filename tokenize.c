#include"shell.h"

char **_strtok(char *cmd, const char *delim);
char **tokenize(char *cmd);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * _strtok - breaks string cmd into a series of
 * tokens using the delimiter delim and assigne needded memory for returning
 * a 2d array of token
 * @cmd: the contents of this string are modified and
 * broken into smaller strings
 * @delim: This is the string containing the delimiters
 *
 * Return: return a list of token
 */
char **_strtok(char *cmd, const char *delim)
{
	char *token = NULL, **token_list = NULL;
	int i = 0;

	token = strtok(cmd, delim);
	while (token)
	{
		token_list = _realloc(token_list, sizeof(char *) * i
				, sizeof(char *) * (i + 1));
		if (token_list == NULL)
		{
			return (NULL);
		}
		token_list[i] = malloc(_strlen(token) + 1);
		if (token_list[i] == NULL)
		{
			return (NULL);
		}
		_strcpy(token_list[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	token_list = _realloc(token_list, sizeof(char *) * i
			, (i + 1) * sizeof(char *));
	if (token_list == NULL)
	{
		return (NULL);
	}
	token_list[i] = NULL;
	return (token_list);
}

/**
 * tokenize - define the delimiter of _strtok and return the token list
 * @cmd: the string to tokenize
 *
 * Return: the token list in the form of a 2d array
 */
char **tokenize(char *cmd)
{
	char **token = NULL, *tmp = NULL;

	tmp = _strdup(cmd);
	if (tmp == NULL)
	{
		_puts("memory allocated error");
		exit(EXIT_FAILURE);
	}
	token = _strtok(tmp, " \t\r\n\a");
	free(tmp);
	return (token);
}

/**
 * *_realloc -  function that reallocates a memory block using malloc and free
 * @ptr: the old memory block
 * @old_size: the size of the old memeory block
 * @new_size: the size to assigne to the new memory block
 *
 * Return: a pointer to the new memory block, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *np;
	char *op = ptr;
	unsigned int i;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (!(ptr == NULL) && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	np = malloc(new_size);
	if (np == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < old_size && i < new_size; i++)
	{
		np[i] = op[i];
	}
	free(ptr);
	return (np);
}
