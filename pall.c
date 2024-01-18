#include "monty.h"

/**
 * pall_func - prints stack
 * @h: head
 * @count: line number
 */

void pall_func(stack_t **h, unsigned int count)
{
	stack_t *head;
	(void)count;

	head = *h;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
