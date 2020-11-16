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
int findenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);

int main(void)
{
	char *PATH;

	PATH = _getenv("PATH");
	printf("PATH: %s\n", PATH);
	_setenv("FOO", "bar", 1);
	printf("FOO: %s\n", _getenv("FOO"));
	return (0);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *var, **tmp;
	int len = 0, idx;

	idx = findenv(name);
	var = environ[idx];
	len = strlen(name) + 1 + strlen(value) + 1;

	if (!var || overwrite != 0)
	{
		if (var)
			free(var);
		else
			environ[idx + 1] = NULL;
		environ[idx] = malloc(sizeof(char) * len);
		strcpy(environ[idx], name);
		strcat(environ[idx], "=");
		strcat(environ[idx], value);
		return (0);
	}
	return (0);
}

int findenv(const char *name)
{
	int i = 0;
	char **n_v, *n;

	for (i = 0; environ[i]; ++i)
	{
		n_v = split_delim(environ[i], "=");
		n = n_v[0];
		if (!strcmp(n, name))
			return (i);
	}
	return (i);
}

char *_getenv(const char *name)
{
	char *env;

	if ((env = environ[findenv(name)]))
		return (strstr(env, "=") + 1);
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
