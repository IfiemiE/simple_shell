#include "main.h"

/**
  * parser - parses the command string
  * before passing command units for execution
  * @str: command string
  * Return: integers when successful
  */
int parser(char *str)
{
	char **cmds;
	int nc, fval;
	void (*cmd_func)(char *a, char *b);

	nc = word_count(str);
	if (nc == 0)
		return (0);

	cmds = splits(str);
	if (cmds == NULL)
		perror("Error");
	if (strcmp("exit", cmds[0]) == 0)
		return (-1);
	cmd_func = check_command(cmds[0]);
	if (cmd_func != NULL)
	{
		fval = fork();
		if (fval < 0)
			perror("Error");
		else if (fval == 0)
		{
			if (nc == 1)
				cmd_func(cmds[0], NULL);
			else if (nc == 2)
				cmd_func(cmds[0], cmds[1]);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("%s: command not found\n", cmds[0]);
		return (127);
	}
	return (0);
}
