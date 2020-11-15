#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t characters;

/*	line = malloc(len * sizeof(char));
	if (line == NULL)
		return (0);
*/
	printf("$ ");

	characters = getline(&line, &len, stdin);

	printf("%s", line);

	free(line);
	return (characters);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("Type something: ");
	characters = getline(&buffer,&bufsize,stdin);
	printf("%lu characters were read.\n",characters);
	printf("You typed: '%s'\n",buffer);

	return(0);
}
*/
