#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
  * struct commandLib - a collection of operable commands
  * @cmd: entered command
  * @cmdptr: a function pointer to given command
  */
typedef struct command_lib
{
	char *cmd;
	void (*f)(char *a, char *b);
} cmdlib;


void set_pathprompt(char *, char *);
char *get_command(void);
int parser(char *);
int _strlen(char *);
int word_count(char *);
char **splits(char *);
void (*check_command(char *s))(char *, char *);
int is_cmdchar(char);





#endif
