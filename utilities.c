#include <stdlib.h>
#include <stdio.h>

/**
 * error - displays error message and exits with EXIT_FAILURE
 * @msg: the error message to display.
 */

void error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
 * _strdup - copies a string to a new memory location.
 * @str: the string parameter to copy to new memory location.
 * Return: pointer to the new memory location.
 */

char *_strdup(char *str)
{
	int i;
	char *s;

	if (str == 0)
		return (0);

	for (i = 0; str[i]; i++)
		;

	s = malloc(sizeof(char) * (i + 1));

	if (s != 0)
	{
		for (; i >= 0; i--)
			s[i] = str[i];
		return (s);
	}
	return (0);
}

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: a pointer to the memory previously allocated with a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size: the new size, in bytes of the new memory block.
 * Return: pointer to the newly allocated memory.
 *         ptr if new_size == old_size.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min;
	char *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	if (old_size < new_size)
		min = old_size;
	else
		min = new_size;

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < min; i++)
		new_ptr[i] = ((char *) ptr)[i];

	free(ptr);
	return ((void *) new_ptr);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
