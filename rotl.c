#include "monty.h"

/**
 * rotl_func - rotates the stack
 * @h: head
 * @count: line number
 *
 */
void rotl_func(stack_t **h, unsigned int count)
{
	stack_t *curr, *temp;
	(void)count;

	curr = *h;

	if (*h == NULL || (*h)->next == NULL)
		return;

	temp = (*h)->next;
	temp->prev = NULL;
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = *h;
	(*h)->next = NULL;
	(*h)->prev = curr;
	(*h) = temp;
}
