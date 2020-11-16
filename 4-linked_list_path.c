#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listpathdir_s
{
	char *dir;
	struct listpathdir_s *next;
} listpathdir_t;

extern char **environ;

char **split_delim(char *, const char *);
char * _getenv(const char *name);
listpathdir_t *build_list(char *);

int main(void)
{
	char *PATH;

	PATH = _getenv("PATH");
	printf("PATH: %s\n", PATH);
	build_list(PATH);
	return (0);
}

listpathdir_t *build_list(char *PATH)
{
	int i = 0;
	char **whole_path;
	listpathdir_t *new, *head = NULL;

	whole_path = split_delim(PATH, ":");
	new = malloc(sizeof(listpathdir_t));
	if (!new)
		return (NULL);

	for (i = 0; whole_path[i]; ++i)
	{
		new->dir = strdup(whole_path[i]);
		new->next = head;
		head = new;
	}
	return (head);
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
