#include "main.h"

/**
  * check_command - compares command with a preset
  * command list
  * @s: the entered command
  * Return: a function associated with the command
  */
void (*check_command(char *s))(char *cmd, char *arg)
{
	cmdlib cmd_lib[] = {
		{NULL, NULL},
	};
	int i = 0;

	while (cmd_lib[i].cmd != NULL)
	{
		if (strcmp(s, cmd_lib[i].cmd) == 0)
			return (cmd_lib[i].f);
		i++;
	}
	return (NULL);
}

