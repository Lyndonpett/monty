#include "monty.h"

/**
 * pushOP - performs push op
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */

void pushOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	int i;

	if (!opGlobal[1])
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		freeList(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	i = atoi(opGlobal[1]);
	if (i == 0 && opGlobal[1][0] != '0')
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		freeList(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	add_node(stack, i, opcode, fd);
}
/**
 * pallOP - performs pall
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void pallOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	(void)opcode;
	(void)fd;
	(void)line_num;
	if (*stack)
	{
		pallHELPER(*stack);
	}
}
/**
 * pintOP - performs pint
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void pintOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack = stack;
	line_num = line_num;
	opcode = opcode;
	fd = fd;
}
/**
 * popOP - performs pop op
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void popOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack = stack;
	line_num = line_num;
	opcode = opcode;
	fd = fd;
}
/**
 * swapOP - performs swap op
 *
 * @stack: the list
 * @line_num: line number.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */
void swapOP(stack_t **stack, unsigned int line_num, char *opcode, FILE *fd)
{
	stack = stack;
	line_num = line_num;
	opcode = opcode;
	fd = fd;
}
