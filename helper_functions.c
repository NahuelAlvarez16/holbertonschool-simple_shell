#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
/**
 * _strcpy - Copies the string pointed to by src
 * @dest: Destined
 * @src: Contens
 * Return: return src variable
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * _strcmp - Comparate two strings
 * @s1: First string
 * @s2: Second string
 * Return: Result of the comparatin
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _strlen - length of a string
 * @s: string
 * Return: return length of a s variable
 */
int _strlen(char *s)
{
	int length = 0;

	while (*(s + length))
		length++;
	return (length);
}
/**
 * _strcat - Concatenates two strings.
 * @dest: Destined
 * @src: Contens
 * Return: return src variable
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int length = 0;

	while (dest[length])
		length++;

	while (src[i])
	{
		dest[length] = src[i];
		length++;
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
