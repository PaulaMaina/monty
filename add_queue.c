#include "monty.h"

/**
 * queue_func - print the top element
 * @h: head
 * @count: line number
 *
 */
void queue_func(stack_t **h, unsigned int count)
{
	(void)h;
	(void)count;
	bus.chg_flag = 1;
}

/**
 * add_queue - add a node to the tail stack
 * @n: new integer
 * @h: head
 *
 */

void add_queue(stack_t **h, int n)
{
	stack_t *new_node, *temp;

	temp = *h;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}

	if (!temp)
	{
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
