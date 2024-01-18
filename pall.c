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

	for (; head != NULL; head = head->next)
		printf("%d\n", head->n);
}
