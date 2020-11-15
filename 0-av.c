#include <stdio.h>

/**
 * main - prints all arguments it receives from command line
 * @argc: number of command line arguments & size of array argv
 * @argv: array containing the program command line arguments
 *
 * Return: Always 0
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	int i;

	for (i = 0; argv[i]; ++i)
		printf("%s\n", argv[i]);
	return (0);
}
