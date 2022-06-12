#include "shell.h"

/**
* find_builtins - finds built-ins from the list of built-ins based on user input
* @tokens: pointer to user input
* Return: 0 if found a built-ins, else -1
**/
int find_builtins(char **tokens)
{
	int sun;
	in_built list[] = {{"alias", whichAlias},
			     {"cd", chng_dr},
			     {"env", printEnv},
			     {"exit", ext},
			     {"help", hlp},
			     {"history", printHistory},
			     {"printenv", printEnv},
			     {"setenv", _setenv},
			     {"unsetenv", _unsetenv},
			     {NULL, NULL}
	};

	for (sun = 0; list[sun].s != NULL; sun++)
	{
		if (_strcmp(tokens[0], list[sun].s) == 0)
		{
			list[sun].func(tokens);
			return (0);
		}
	}
	return (-1);
}

/**
* check_path - checks the PATH variable for finding the binary of given program
* @tokens: pointer to user input
* @p: pointer to memory
* Return: nothing
**/
void check_path(char **tokens, char *p)
{
	char *path, **tokn, *concat;

	path = _getenv("PATH");
	tokn = parse_path(path, ':');
	while (*tokn)
	{
		concat = _strcat(*tokn, tokens[0], '/');
		if (concat)
		{
			if (execve(concat, tokens, NULL) != -1)
				break;
		}
		tokn++;
	}
	_puts("No such command found\n");
	_ref_mem(&p, "remove child");
	_exit(1);
}
