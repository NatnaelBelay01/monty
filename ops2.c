#include "monty.h"
/**
 * pint - a function to print the top value
 * @stack: apointer to the top of the stack
 * @num: the line number
 */
void pint(stack_t **stack, size_t num)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%ld: can't pint, stack\n", num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pall - a function that prints all the values of a stack
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void pall(stack_t **stack, size_t num)
{
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
			num--;
		}
	}
}
/**
 * swap - a function that swaps the top two value of a stack
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void swap(stack_t **stack, size_t num)
{
	int val_1, val_2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	val_1 = (*stack)->n;
	val_2 = (*stack)->next->n;
	(*stack)->next->n = val_1;
	(*stack)->n = val_2;
}
/**
 * add - a function that adds the top two values of a stack
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void add(stack_t **stack, size_t num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, num);
}
/**
 * nop - a function that literally does nothing
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void nop(stack_t **stack, size_t num)
{
	(void)stack;
	(void)num;
}
