#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char *argv[] = {"/bin/ls", NULL};

	for (i = 0; i < 5; i++)
	{
		if (fork() == 0)
			execve(argv[0], argv, NULL);
		else
			wait(NULL);
	}
	return (0);
}
