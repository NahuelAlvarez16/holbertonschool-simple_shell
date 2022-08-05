#include "main.h"
int str_starts_with(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i] && s2[i + 1] == 0)
			return (1);
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (0);
}
