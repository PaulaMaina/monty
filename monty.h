#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
	struct stack_s *prev;
} stack_t;
/**
 * struct bus_s - variables
 * @args: values
 * @file: pointer to the monty file
 * @cont: content of the line
 * @chg_flag: flag to change stack to queue and vice versa
 */
typedef struct bus_s
{
	char *args;
	FILE *file;
 	char *cont;
	int chg_flag;
} bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stacks, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_func(stack_t **h, unsigned int count);
void pall_func(stack_t **h, unsigned int count);
void pint_func(stack_t **h, unsigned int count);
void pop_func(stack_t **h, unsigned int count);
void swap_func(stack_t **h, unsigned int count);
void nop_func(stack_t **h, unsigned int count);
void sub_func(stack_t **h, unsigned int count);
void mul_func(stack_t **h, unsigned int count);
void mod_func(stack_t **h, unsigned int count);
void pchar_func(stack_t **h, unsigned int count);
void pstr_func(stack_t **h, unsigned int count);
void rotl_func(stack_t **h, unsigned int count);
void add_func(stack_t **h, unsigned int count);
void addnode(stack_t **h, int n);
void div_func(stack_t **h, unsigned int count);
void rotr_func(stack_t **h, unsigned int count);
void stack_func(stack_t **h, unsigned int count);
void queue_func(stack_t **h, unsigned int count);
void add_queue(stack_t **h, int n);
void free_stack(stack_t *h);
int execute_op(char *cont, stack_t **stack, unsigned int count, FILE *file);

#endif	/* MONTY_H */
