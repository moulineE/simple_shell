#include"shell.h"

void _puts(char *str);
int _putchar(char c);
void _errputs(char *str);
char *_strcat(char *dest, char *src);

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

void _errputs(char *str)
{
	char *str1;
	size_t len;
	ssize_t str_bytes;

	str1 = _getenv("_");
	_strcat(str1, ": 1: ");
	_strcat(str1, str);
	len = _strlen(str1);
	str_bytes = write(STDERR_FILENO, str1, len);
	if (str_bytes == -1)
	{
		perror("write");
	}
	len = _strlen(": not found\n");
	str_bytes = write(STDERR_FILENO, ": not found\n", len);
	if (str_bytes == -1)
	{
		perror("write");
	}
}
/**
 * *_strcat - a function that concatenates two strings.
 * @dest: the destionation to concatenates
 * @src: the string to copy
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int m;

	i = 0;
	while (*(dest + i) > 0)
	{
		i++;
	}
	for (m = 0; *(src + m) > 0; m++)
	{
		*(dest + i) = *(src + m);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}
