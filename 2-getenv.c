#include <stdio.h>

/*
char **split_env(char *);
*/
char * _getenv(const char *name);

int main(__attribute__((unused)) int ac, __attribute__((unused)), char *av[], char **env)
{
	char *PATH;

	PATH = _getenv("PATH");
	printf("PATH: %s\n", PATH);
}

char * _getenv(const char *name)
{
	int i = 0;

	

/*
char **split_env(char *my_env)
{
	char *my_env1, *env_var;
	int i = 0, j = 0;
	char **full_env;

	my_env1 = strdup(my_env);
	env_var = strtok(line, ":");

	while (env_var)
	{
		i++;
		env_var = strtok(NULL, "\0");
	}

	full_env = malloc(sizeof(char *) * (i + 1));

	env_var = strtok(my_env1, "\0");

	while (env_var)
	{
		array[j++] = env_var;
		env_var = strtok(NULL, "\0");
	}

	return (full_env);
}
*/
