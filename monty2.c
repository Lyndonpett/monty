#include "monty.h"

/**
 * addOP - performs add op
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void addOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack_t *tmp, *cog;

	if (*stack == NULL ||
	    (((*stack)->prev == NULL) && (*stack)->next == NULL))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_num);
		freeList(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	for (tmp = *stack; tmp->prev; tmp = tmp->prev)
	{
	}
	cog = tmp->next;
	if (tmp == *stack)
	{
		*stack = cog;
	}
	cog->n = tmp->n + cog->n;
	cog->prev = NULL;
	free(tmp);
}
/**
 * nopOP - performs add op
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void nopOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack = stack;
	line_num = line_num;
	opcode = opcode;
	fd = fd;
}
