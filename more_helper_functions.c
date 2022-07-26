#include "main.h"
/**
 * _puts - Print a string
 * @str: string
 */
void _puts(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		_putchar(*(str + i));
		i++;
	}
}
/**
 * _strdup - pointer to a newly allocated space in memory
 * @str: string
 * Return: return array
 */
char *_strdup(char *str)
{
	char *temp;
	unsigned int i = 0;
	unsigned int size = 0;

	if (str == NULL)
		return (NULL);

	for (; str[size]; size++)
		;

	temp = malloc(size + 1);

	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/**
 * _getenv - Get variable content of a variable environment variable
 * @env: Name of environment variable
 * Return: return the content of environment variable
 */
char *_getenv(char *env)
{
	char *aux;
	char *content;
	int i = 0;

	for (; environ[i]; i++)
	{
		aux = _strdup(environ[i]);
		aux = strtok(aux, "=");
		if (_strcmp(aux, env) == 0)
		{
			content = _strdup(strtok(NULL, "="));
			free(aux);
			return (content);
		}
		free(aux);
	}
	return (NULL);
}
/**
* _which - checks and finds the path of the command passed to it
* @cmd: command
* Return: the absolute path of the comand
*/

char *_which(char *cmd)
{
	char *paths = NULL;
	char *path = NULL;
	char *cmd_path = NULL;

	paths = _getenv("PATH");
	if (paths)
		path = strtok(paths, ":");

	if (_strchr(cmd, '/') && stat(cmd, &st) == 0)
	{
		if (path)
			free(path);
		return (_strdup(cmd));
	}
	while (path)
	{
		cmd_path = malloc(sizeof(char) * _strlen(path) + _strlen(cmd) + 2);
		if (!cmd_path)
			return (NULL);
		cmd_path[0] = '\0';
		_strcat(cmd_path, path);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) ==  0)
		{
			free(paths);
			return (cmd_path);
		}
		path = strtok(NULL, ":");
		free(cmd_path);
	}
	if (paths)
		free(paths);
	return (NULL);
}
/**
* _execve - Is used to execute the program referenced by the path.
* @args: pointer to pointer argument string
* Return: return exit status of program
*/

int _execve(char **args)
{
	int status = 0;

	if (fork() == 0)
	{
		execve(args[0], args, environ);
	}
	else
		wait(&status);
	return (WEXITSTATUS(status));
}
