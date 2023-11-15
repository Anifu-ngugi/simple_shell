#include "shell.h"

/**
 * my_wait - makes sure that the parent process waits for the child
 * @childPid: A child process known as cmdChild
 * @promptStr: The input that the user enters after the prompt
 *
 * Return: void
 */
void my_wait(pid_t childPid, char *promptStr)
{
	pid_t termChild;
	int status;

	termChild = waitpid(childPid, &status, 0);

	if (termChild == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
		free(promptStr);
	}
}
