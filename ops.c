#include "monty.h"
/**
 * push - a fucntion that pushs a value to the stack
 * @stack: a pointer to the top of the stack
 * @num: the line number
 * @val: the value to be pushed
 */
void push(stack_t **stack, size_t num, char *val)
{
	stack_t *new;
	int i;

	if (val == NULL)
	{
		dprintf(2, "L%ld: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; val[i] != '\0'; i++)
	{
		if (i == 0 && val[i] == '-')
			continue;
		if (isdigit(val[i]) == 0)
		{
			dprintf(2, "L%ld: usage: push integer\n", num);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(val);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * pop - a function that deletes a value from the stack
 * @stack: a pointer to the top the stack
 * @num: the line number
 */
void pop(stack_t **stack, size_t num)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%ld: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
