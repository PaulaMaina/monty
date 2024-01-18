#include "monty.h"

/**
 * addnode - adds  new node to the head
 * @h: head
 * @n: integer
 *
 */

void addnode(stack_t **h, int n)
{
	stack_t *new_node, *temp;

	temp = *h;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *h;
	new_node->prev = NULL;
	*h = new_node;
}
