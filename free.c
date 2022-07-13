#include "monty.h"
/**
 * sfree - a function that frees the stack
 * @stack: apointer to the top of the stack
 */

void sfree(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack != NULL)
	{
		(*stack) = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}
