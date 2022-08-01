#include "main.h"
int main(int argc,char **argv)
{
	char *buffer = NULL;
	size_t len = 0;
	char *cmd_path = NULL;
	
	if (argc > 1)
	{
		_puts("PEPEP");
		cmd_path = _which(argv[1]);
		_execve(cmd_path);
		free(cmd_path);
		return (0);
	}
	while (argc == 1 && ( !buffer || (_strcmp(buffer, "exit") != 0)))
	{
		if (getline(&buffer, &len, stdin) == -1)
		{
			_putchar('\n');
			free(buffer);
			return (0);
		}
		strtok(buffer, "\n");
		cmd_path = _which(buffer);
		_execve(cmd_path);
		if (cmd_path)
			free(cmd_path);
	}
	return (0);
}

