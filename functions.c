#include "main.h"
/**
 * _strlen - function that returns the length of a string
 * @s : string
 * Return: lenght of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcpy - function that copy string
 * @dest : pointer to array
 * @src : pointer to array
 * Return: pointer to the copied array
 */

char *_strcpy(char *dest, char *src)
{
	int i, len = _strlen(src);

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
