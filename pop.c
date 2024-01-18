#include "monty.h"

/**
 * pop_func - removes the top element
 * @h: head
 * @count: line number
 *
 */

void pop_func(stack_t **h, unsigned int count)
{
	stack_t *head;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	*h = head->next;
	free(head);
}
