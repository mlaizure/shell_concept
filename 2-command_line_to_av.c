#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split (char *);

int main (void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t characters;
	char **array;
	int i = 0;

	printf("$ ");

	characters = getline(&line, &len, stdin);

	array = split(line);

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}

	free(line);
	return (characters);
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
