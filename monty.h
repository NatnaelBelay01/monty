#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#define DELI "\n\t\r "

/**
 * struct stack_s - a doubly linked list representation of stacks
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next elemnet
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instructions_s - opcode and its functions
 * @opcode: the opcode
 * @f: fucntion to handle the opcode
 */
typedef struct instructions_s
{
	char *opcode;
	void (*f)(stack_t **stack, size_t num);
} instruction_t;

void push(stack_t **stack, size_t num, char *val);
void pop(stack_t **stack, size_t num);
void pint(stack_t **stack, size_t num);
void pall(stack_t **stack, size_t num);
void swap(stack_t **stack, size_t num);
int op_sel(stack_t **stack, size_t num, char *op);
void sfree(stack_t **stack);
void add(stack_t **stack, size_t num);
void nop(stack_t **stack, size_t num);
void sub(stack_t **stack, size_t num);
void divd(stack_t **stack, size_t num);
void mul(stack_t **stack, size_t num);
void mod(stack_t **stack, size_t num);
#endif
