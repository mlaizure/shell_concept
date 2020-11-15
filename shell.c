#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **split (char *line);

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n_characters;
	char **array;

	while (1)
	{
		printf("$ ");

		n_characters = getline(&line, &len, stdin);
		line[n_characters - 1] = '\0';

		array = split(line);

		if (fork() == 0)
			execve(array[0], array, NULL);
		else
		{
			wait(NULL);
			free(line);
			line = NULL;
		}
	}
	return (n_characters);
}

char **split (char *line)
{
	char *line1, *words;
	int i = 0, j = 0;
	char **array;

	line1 = strdup(line);
	words = strtok(line, " ");

	while (words)
	{
		i++;
		words = strtok(NULL, " ");
	}

	array = malloc(sizeof(char *) * (i + 1));

	words = strtok(line1, " ");

	while (words)
	{
		array[j++] = words;
		words = strtok(NULL, " ");
	}

	return (array);
}
