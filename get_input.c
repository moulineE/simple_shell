#include"shell.h"

static char *last_input;
/**
 * get_input - Read the line of the input user
 *
 * Return: Pointer to a buffer containig the user input .
 */

char *get_input(void)
{
	char *cmd = NULL;
	size_t bufsize = 0;
	ssize_t size_name;

	do {
		if (isatty(STDIN_FILENO))
			prompt();
		size_name = getline(&cmd, &bufsize, stdin);
		if (size_name == -1)
		{
			free(cmd);
			return (NULL);
		}
		cmd[size_name - 1] = '\0';
	} while (*cmd == '\0' || cmd == NULL);

	last_input = cmd;
	return (cmd);
}

/**
 * free_last_input - Frees the most recent input entered by the user.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
