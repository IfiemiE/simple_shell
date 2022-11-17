#include "main.h"
/**
  * get_command - gets command from STDIN
  *
  * Return: pointer to the command string
  */
char *get_command(void)
{
	size_t n = 50;
	int confirm;
	char *buffer = malloc(n * sizeof(char));

	if (buffer == NULL)
	{
		perror("Error");
	}

	confirm = getline(&buffer, &n, stdin);
	if (confirm == -1)
	{
		if (isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
	}

	return (buffer);
}
