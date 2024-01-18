#include "monty.h"

/**
 * execute_op - execute opcode
 * @stack: stack
 * @count: line number
 * @file: points to the monty file
 * @cont: content of the line
 *
 */

int execute_op(char *cont, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t ops_f[] = {
		{"push", push_func}, {"pall", pall_func},
		{"pint", pint_func}, {"pop", pop_func},
		{"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {"sub", sub_func},
		{"div", div_func}, {"mul", mul_func},
		{"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func}, {"rotl", rotl_func},
		{"rotr", rotr_func}, {"queue", queue_func},
		{"stack", stack_func}, {NULL, NULL}
	};
	char *op;
	unsigned int x = 0;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.args = strtok(NULL, " \n\t");
	while (ops_f[x].opcode && op)
	{
		if (strcmp(op, ops_f[x].opcode) == 0)
		{
			ops_f[x].f(stack, count);
			return (0);
		}
		x++;
	}
	if (op && ops_f[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
