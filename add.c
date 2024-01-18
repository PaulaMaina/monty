#include "monty.h"

/**
 * add_func - adds the two top stack elements
 * @h: head
 * @count: line number
 *
 */

void add_func(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	tmp = head->n + head->next->n;
	head->next->n = tmp;
	*h = head->next;
	free(head);
}
