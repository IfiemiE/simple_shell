#include "main.h"

/**
  * main - parent function; begins command line execution
  * before calling other functions
  *
  * Return: 0 always
  */
int main(void)
{
	int pval;

	while (1)
	{
		char *cmd;

		set_pathprompt(NULL, "$");

		cmd = get_command();

		pval = parser(cmd);

		free(cmd);

		if (pval == -1)
		{
			break;
		}
	}
	return (0);
}
