#include "main.h"
char **generate_arguments(char *s)
{
	char **args;
	int i = 0;
	int x = -1;
	int index = 0;
	int length = 0;

	for (i = 0; s && s[i]; i++)
	{
		if (s[i] != ' ' && (!s[i + 1] || s[i + 1] == ' '))
		{
			length++;
		}
	}
	args = malloc(sizeof(char *) * (length + 1));
	for (i = 0; s && s[i]; i++)
	{
		if (s[i] != ' ')
		{
			if (x == -1)
			{
				for (length = 0, x = i; s[x] && s[x] != ' '; x++, length++)
					;
				x = 0;
				args[index] = malloc(sizeof(char *) * length + 1);
			}
			args[index][x] = s[i];
			x++;
			if ((!s[i + 1] || s[i + 1] == ' '))
			{
				args[index][x] = '\0';
				x = -1;
				index++;
			}
		}
	}
	args[index] = NULL;
	return (args);
}

int main(int argc,char **argv)
{
	char *buffer = NULL;
	size_t len = 0;
	char *cmd;
	char **args;
	int i;
	if (argc > 1)
	{
		_execve(&argv[1]);
		return (0);
	}
	while (argc == 1)
	{
		if (getline(&buffer, &len, stdin) == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			if (buffer)
				free(buffer);
			return (0);
		}
		cmd = _strdup(buffer);
		strtok(cmd, "\n");
		args = generate_arguments(cmd);
		if (args[0])
		{
			_execve(args);
		}
		free(cmd);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	return (0);
}
