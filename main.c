#include "main.h"
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
void _perror(char *name,char *cmd)
{
	char *msg = NULL;
	int length = sizeof(char) * (_strlen(name) + _strlen(cmd) + 17);
	msg = malloc(length);
	_strcat(msg, name);
	_strcat(msg, ": ");
	_strcat(msg, cmd);
	_strcat(msg, ": not found\n");
	write(2, msg, length);
	free(msg);
}
int main(int argc, char **argv)
{
	char *buffer = NULL;
	int fd = 0;
	size_t len = 0;
	char *cmd;
	char **args;
	int i;
	int status = 0;

	if (argc > 1)
	{
		argv[1] = _which(argv[1]);
		_execve(&argv[1]);
		free(argv[1]);
		return (0);
	}
	while (argc == 1)
	{
		if (isatty(fd) == 1)
			_puts("$ ");
		if (getline(&buffer, &len, stdin) == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			if (buffer)
				free(buffer);
			exit(status);
		}
		cmd = _strdup(buffer);
		strtok(cmd, "\n");
		args = generate_arguments(cmd, "\t \n");
		free(cmd);
		if (_strcmp(args[0], "env") == 0)
		{
			for (i = 0; environ && environ[i]; i++) {
				_puts(environ[i]);
				_putchar('\n');
			}
		}
		else if (args[0])
		{
			cmd = _which(args[0]);
			if (cmd)
			{
				free(args[0]);
				args[0] = cmd;
				status = _execve(args);
			}
			else
			{
				status = 127;
				perror(args[0]);
			}
		}
		_perror(argv[0], args[0]);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	return (0);
}
