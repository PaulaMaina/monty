#include "monty.h"

/**
 * pstr_func - prints the string from the top of the stack downwards
 * @h: head
 * @count: line number
 *
 *
 */
void pstr_func(stack_t **h, unsigned int count)
{
	stack_t *head;
	(void)count;

	head = *h;
	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
