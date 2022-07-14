#include "monty.h"
/**
 * sub - a function that does calculations
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void sub(stack_t **stack, size_t num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, num);
}

/**
 * divd - a function that does calculations
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void divd(stack_t **stack, size_t num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%ld: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, num);
}


/**
 * mul - a function that does calculations
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void mul(stack_t **stack, size_t num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, num);
}

/**
 * mod - a function that does calculations
 * @stack: a pointer to the top of the stack
 * @num: the line number
 */
void mod(stack_t **stack, size_t num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%ld: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%ld: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, num);
}
