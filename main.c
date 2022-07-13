#include "monty.h"
/**
 * main - the main function
 * @ac: the number of rguments
 * @av: an array of the argument
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL, *op;
	size_t bufsiz, line_num = 0;
	ssize_t linesiz;
	FILE *fd;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	linesiz = getline(&line, &bufsiz, fd);
	while (linesiz != -1)
	{
		line_num++;
		op = strtok(line, DELI);
		if (op == NULL || strncmp(op, "#", 1) == 0 || strcmp(line, DELI) == 0)
		{
			linesiz = getline(&line, &bufsiz, fd);
			continue;
		}
		if (strcmp(op, "push") == 0)
		{
			op = strtok(NULL, DELI);
			push(&stack, line_num, op);
		}
		else if (linesiz > 1)
			op_sel(&stack, line_num, op);
		linesiz = getline(&line, &bufsiz, fd);
	}
	fclose(fd);
	sfree(&stack);
	free(line);
	return (EXIT_SUCCESS);
}
