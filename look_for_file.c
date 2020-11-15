#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **split (char *line);

/**
 * main - stat example
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	unsigned int i = 0, j = 0;
	struct stat st;
	char *PATH, **whole_path;
	char current_path[1024];

	if (ac < 2)
	{
		printf("Usage: ./stat filename\n");
		return (1);
	}

	PATH = getenv("PATH");
	whole_path = split(PATH);

	i = 1;
	while (av[i])
	{
		j = 0;
		while (whole_path[j])
		{
			strcpy(current_path, whole_path[j]);
			strcat(current_path, "/");
			strcat(current_path, av[i]);
			if (stat(current_path, &st) == 0)
			{
				printf("%s: %s\n", av[i], current_path);
				break;
			}
			++j;
		}
		i++;
	}
	return (0);
}

char **split (char *line)
{
	char *line1, *words;
	int i = 0, j = 0;
	char **array;

	line1 = strdup(line);
	words = strtok(line, ":");

	while (words)
	{
		i++;
		words = strtok(NULL, ":");
	}

	array = malloc(sizeof(char *) * (i + 1));

	words = strtok(line1, ":");

	while (words)
	{
		array[j++] = words;
		words = strtok(NULL, ":");
	}

	return (array);
}
