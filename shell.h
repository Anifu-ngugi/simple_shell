#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void fork_execve(char *inputStr);
void my_wait(pid_t childPid, char *promptStr);
int my_strcmp(const char *str1, const char *str2);
int argHandler(char *str);

#endif
