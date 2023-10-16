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

/**
 * _strdup -  creates an array a copy of the string given as a parameter.
 *@str: given array
 *Return: pointer to first string
 */
char *_strdup(char *str)
{
	char *ptr;
	int i;
	int size;

	if (str == NULL)
	{
		return (NULL);
	}
	for (size = 0; str[size] != '\0'; size++)
		continue;
		
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		*(ptr + i) = *(str + i);
	}
	*(ptr + size) = '\0';
	return (ptr);
}

/**
 *_strcmp - function that compares two strings
 *@s1: the first pointer
 *@s2: string to be copied
 *
 * Return: integer
 */

/* int _strncmp(char *s1, char *s2, size_t n)
{
int i;

for (i = 0; s1[i] != '\0' || s2[i] != '\0' && n; i++, n--)
{
	if (s1[i] != s2[i])
	{
	break;
	}
	else
	continue;
}
return (s1[i] - s2[i]);
} */