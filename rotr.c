#include "monty.h"

/**
 * rotr_func - rotates the stack to the bottom
 * @h: head
 * @count: line number
 *
 */
void rotr_func(stack_t **h, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *h;

	if (*h == NULL  || (*h)->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

	temp->next = *h;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*h)->prev = temp;
	(*h) = temp;
}
