#include "shell.h"

/**
 * fork_execve - creates a child process cmdChild to execute a system call
 *
 * @inputStr: The input that the user enters after the prompt
 *
 * Return: 0 (Success) Always
 */
void fork_execve(char *inputStr)
{
	pid_t cmdChild;
	extern char **environ;
	char *token;
	char *args[10];
	int argCount = 0;

	token = strtok(inputStr, " ");
	while (token != NULL)
	{
		args[argCount++] = token;
		token = strtok(NULL, " ");
	}
	args[argCount] = NULL;

	cmdChild = fork();
	if (cmdChild == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cmdChild == 0)
	{
		if (execve(args[0], args, environ) == -1)
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
