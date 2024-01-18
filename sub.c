#include "monty.h"

/**
 * sub_func - subtracts two elements of the stack
 * @h: head
 * @count: line number
 */
void sub_func(stack_t **h, unsigned int count)
{
	stack_t *temp;
	int len, result;

	temp = *h;

	for (len = 0; temp != NULL; len++)
		temp = temp->next;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*h = temp->next;
	free(temp);
}
