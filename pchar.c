#include "monty.h"

/**
 * pchar_func - prints the character at the top of the stack
 * @h: head
 * @count: line number
 *
 */
void pchar_func(stack_t **h, unsigned int count)
{
	stack_t *head;

	head = *h;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.cont);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
