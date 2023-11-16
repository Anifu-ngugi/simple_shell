#include "shell.h"

/**
 * main - This functions like a shell by executing commands only
 *
 * Return: 0 (Success) Always
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("MyShell/$ ");
		fflush(stdout);

		read = getline(&input, &len, stdin);

		if (read != 1)
		{
			if (input[read - 1] == '\n')
				input[read - 1] = '\0';

			if (my_strcmp(input, "exit") == 0)
				break;

			fork_execve(input);
		}
		else
		{
			printf("Error reading input.\n");
			free(input);
		}
	}
	return (0);
}
