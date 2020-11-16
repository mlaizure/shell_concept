#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char colon = ':';
	char *PATH;

	PATH = getenv("PATH");

	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == colon)
		{
			printf("\n");
		}
		else
			putchar(PATH[i]);
	}
	return (0);
}
