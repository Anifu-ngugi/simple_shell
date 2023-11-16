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
	pid_t cmdChild, childPid;
	extern char **environ;
	char *token;
	char *args[10];
	int argCount = 0;
	char *customPath;
	char **env;

	token = strtok(inputStr, " ");
	while (token != NULL)
	{
		args[argCount++] = token;
		token = strtok(NULL, " ");
	}
	args[argCount] = NULL;
	if (strcmp(args[0], "env") == 0)
	{
		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
	}
	else if (strchr(args[0], '/') == NULL)
	{
		customPath = "usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin";
		setenv("PATH", customPath, 1);
		if (access(args[0], X_OK) == 0)
		{
			childPid = fork();

			if (childPid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (childPid == 0)
			{
				if (execve(args[0], args, environ))
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
				free(inputStr);
			}
			else
			{
				my_wait(childPid, inputStr);
			}
	
		}
		else
		{
			printf("Command not found:\n");
		}
	}
	else
	{
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
}
