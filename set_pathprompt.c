#include "main.h"
/**
  * set_pathprompt - prints the directory, if needed
  * and the command prompt
  * @dir: the directory
  * @prompt: the command prompt
  */
void set_pathprompt(char *dir, char *prompt)
{
	if (prompt == NULL)
		exit(0);
	if (dir != NULL)
		printf("%s%s ", dir, prompt);
	else
		printf("%s ", prompt);
}
