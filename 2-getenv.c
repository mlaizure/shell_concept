#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char **split_delim(char *, const char *);
char * _getenv(const char *name);

int main(void)
{
	char *PATH, *HOME, *DNE;

	PATH = _getenv("PATH");
	HOME = _getenv("HOME");
	DNE = _getenv("DNE");
	printf("PATH: %s\n", PATH);
	printf("HOME: %s\n", HOME);
	printf("DNE: %s\n", DNE);
	return (0);
}

char * _getenv(const char *name)
{
	int i = 0;
	char **n_v, *n;

	for (i = 0; environ[i]; ++i)
	{
		n_v = split_delim(environ[i], "=");
		n = n_v[0];
		if (!strcmp(n, name))
			return (strstr(environ[i], "=") + 1);
	}
	return (NULL);
}

char **split_delim(char *s, const char *delim)
{
	char *s1, *piece, *ptr;
	int i = 0, j = 0;
	char **result;

	for (i = 0, ptr = s; (ptr = strstr(ptr, delim)); ++i, ++ptr)
		;

	result = malloc(sizeof(char *) * (i + 1));

	s1 = strdup(s);

	piece = strtok(s1, delim);

	while (piece)
	{
		result[j++] = piece;
		piece = strtok(NULL, delim);
	}

	return (result);
}
