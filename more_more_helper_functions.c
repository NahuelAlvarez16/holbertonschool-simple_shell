#include "main.h"
/**
 * _strchr - locates a character in a string.
 * @s: string
 * @c: start string since c
 * Return: result
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] && s[i] != c; i++)
		;

	return (s[i] == c ? &s[i] : '\0');
}
/**
* generate_arguments - generates an array with the given arguments
* @s: strings variable to tokenize
* @delimeters: bounding parameters
* Return: full array
*/
char **generate_arguments(char *s, char *delimeters)
{
	char **args;
	int i = 0;
	int length = 0;
	char *s_tmp;
	char *token;

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (length = 0; token; length++)
	{
		token = strtok(NULL, delimeters);
	}
	free(s_tmp);
	args = malloc(sizeof(char *) * (length + 1));
	if (args == NULL)
	{
		return (NULL);
	}

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (i = 0; token; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimeters);
	}
	args[i] = NULL;
	free(s_tmp);
	return (args);
}
/**
* _print_env - function that prints environment variables
*/
void _print_env(void)
{
	int i;

	for (i = 0; environ && environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
/**
 * free_array - frees a 2 dimensional
 * @array: Array
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
/**
* _perror - function generates a standard error message with the last error
* @name: name of program
* @cmd: command
*/

void _perror(char *name, char *cmd)
{
	char *msg = NULL;
	int length = 0;

	length = sizeof(char) * (_strlen(name) + _strlen(cmd) + 18);
	msg = malloc(length);
	if (!msg)
		exit(0);
	msg[0] = '\0';
	_strcat(msg, name);
	_strcat(msg, ": 1: ");
	_strcat(msg, cmd);
	_strcat(msg, ": not found\n");
	write(2, msg, length - 1);
	free(msg);
}
