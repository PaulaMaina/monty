#include "monty.h"

/**
 * push_func - adds a node to the stack
 * @h: head
 * @count: line number
 *
 */
void push_func(stack_t **h, unsigned int count)
{
	int n, i = 0;
	int flag = 0;

	if (bus.args)
	{
		if (bus.args[0] == '-')
			i++;
		for (; bus.args[i] != '\0'; i++)
		{
			if (bus.args[i] > 57 || bus.args[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.cont);
			free_stack(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.args);
	if (bus.chg_flaf == 0)
		addnode(h, n);
	else
		add_queue(h, n);
}
