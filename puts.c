#include"shell.h"
/**
 * _puts - print to user
 * @str: string that we want to print it
 */
void _puts(char *str)
{
	size_t len;
	ssize_t str_bytes;

	len = _strlen(str);
	str_bytes = write(STDOUT_FILENO, str, len);

	if (str_bytes == -1)
	{
		perror("write");
	}
}
/**
 * _putchar - writes a character to stdout
 * @c: character to write
 *
 * Return: On success 1, on error -1 and errno set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
