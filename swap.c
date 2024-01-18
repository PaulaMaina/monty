#include "monty.h"

/**
 * swap_func - swaps the top two elements of the stack
 * @h: head
 * @count: line number
 *
 */
void swap_func(stack_t **h, unsigned int count)
{
	stack_t *head;
	int size = 0, tmp;

	head = *h;

	while (head)
	{
		head = head->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	tmp = head->n;
	head->n = head->next->n;
	head->next->n = tmp;
}
