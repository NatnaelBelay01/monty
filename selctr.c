#include "monty.h"
/**
 * op_sel - a function that selects the op_code
 * @stack: a pointer to the top of the stack
 * @num: the line number
 * @op: the op_code
 * Return: 0 or -1
 */

int op_sel(stack_t **stack, size_t num, char *op)
{
	int i;
	instruction_t ops[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			(ops[i].f)(stack, num);
			return (EXIT_SUCCESS);
		}
	}
	dprintf(2, "L%ld: unknown instruction %s\n", num, op);
	exit(EXIT_FAILURE);
}
