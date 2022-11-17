#include "main.h"

/**
  * is_cmdchar - checks if character is a command character
  * @ch: given character
  * Return: 1, if true, and 0, if false
  */
int is_cmdchar(char ch)
{
	char *upperL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *lowerL = "abcdefghijklmnopqrstuvwxyz";
	char *option_signs = "-";
	int i, val = 0;

	for (i = 0; upperL[i] != '\0'; i++)
	{
		if (ch == upperL[i])
		{
			val = 1;
			break;
		}
	}
	if (val == 0)
	{
		for (i = 0; lowerL[i] != '\0'; i++)
		{
			if (ch == lowerL[i])
			{
				val = 1;
				break;
			}
		}
	}
	if (val == 0)
	{
		for (i = 0; option_signs[i] != '\0'; i++)
		{
			if (ch == option_signs[i])
			{
				val = 1;
				break;
			}
		}
	}

	return (val);
}

/**
  * _strlen - compute the length of a string
  * @s: the string
  * Return: the character count
  */
int _strlen(char *s)
{
	int i, n = 0;

	for (i = 0; s[i] != '\0'; i++)
		n++;
	return (n);
}

/**
  * word_count - counts number of space-separated
  * character sets in a string
  * @s: the given string
  * Return: a non-zero integer
  */
int word_count(char *s)
{
	int i = 0, count = 0;
	int start = 0;
	int v;

	while ((s[i] != '\0') && (_strlen(s) != 0) && (s != NULL))
	{
		v = is_cmdchar(s[i]);
		if ((s[i] != ' ') && (v == 1))
		{
			if (start == 0)
			{
				start = 1;
				count++;
			}

		}
		else
		{
			if (start == 1)
				start = 0;
		}
		i++;
	}
	return (count);
}

/**
  * splits - splits a string into substrings
  * @str: passed-in string
  * Return: a pointer to the first string
  */
char **splits(char *str)
{
	unsigned int ncmd = word_count(str);
	char **token;
	char *p;
	unsigned int n, j, i = 0;

	if (_strlen(str) == 0)
		return (NULL);
	token = malloc(sizeof(*token) * ncmd);
	if (token == NULL)
		perror("ERROR");

	p = strtok(str, " ");
	while (p != NULL)
	{
		n = _strlen(p);
		for (j = 0; j < n; j++)
		{
			if (p[j] == '\n')
				p[j] = '\0';
		}
		token[i] = p;
		p = strtok(NULL, " ");
		i++;
	}
	return (token);
}
