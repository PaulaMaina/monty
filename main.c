#include "monty.h"
#include <stdio.h>
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - main function
 * @argc: argument count
 * @argv: argument list
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char *cont;
	size_t size = 0;
	ssize_t line_read = 1;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1],  "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_read > 0)
	{
		cont = NULL;
		line_read = getline(&cont, &size, file);
		bus.cont = cont;
		count++;
		if (line_read > 0)
			execute_op(cont, &stack, count, file);
		free(cont);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
