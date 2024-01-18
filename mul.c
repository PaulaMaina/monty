#include "monty.h"

/**
 * mul_func - multiples the two top stack elements
 * @h: head
 * @count: line number
 *
 */

void mul_func(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	head = *h;
	tmp = head->next->n * head->n;
	head->next->n = tmp;
	*h = head->next;
	free(head);
}
