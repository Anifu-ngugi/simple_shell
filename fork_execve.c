#include "shell.h"

/*
 * fork_execve - creates a child process cmdChild to execute a system call
 *
 * @inputStr: The input that the user enters after the prompt
 *
 * Return: 0 (Success) Always
 */
void fork_execve(char *inputStr)
{
	pid_t cmdChild;
	char *args[1];
	extern char **environ;

	cmdChild = fork();
	if (cmdChild == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cmdChild == 0)
	{
		args[0] = inputStr;
		args[1] = NULL;

		if (execve(inputStr, args, environ) == -1)
		{
			printf("No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		free(inputStr);
	}
	else
	{
		my_wait(cmdChild, inputStr);
	}
}
