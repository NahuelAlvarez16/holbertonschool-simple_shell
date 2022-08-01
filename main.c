#include "main.h"
int main(int argc,char **argv)
{
	char *buffer = NULL;
	size_t len = 0;
	char *cmd_path = NULL;
	char *cmd;

	if (argc > 1)
	{
		_puts("PEPEP");
		cmd_path = _which(argv[1]);
		_execve(cmd_path);
		free(cmd_path);
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
		cmd_path = _which(cmd);
		if (cmd_path)
		{
			_execve(cmd_path);
			free(cmd_path);
		}
		if (cmd)
			free(cmd);
	}
	return (0);
}

