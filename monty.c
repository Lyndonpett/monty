#include "monty.h"

/**
 * @brief
 *
 *
 *
 */

void pushOP(stack_t **stack, unsigned int line_num)
{
	int i;

	if (!opGlobal[1])
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	i = atoi(opGlobal[1]);
	if (i == 0 && opGlobal[1][0] != '0')
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	add_node(stack, i);
}
void pallOP(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	if (*stack)
	{
		pallHELPER(*stack);
	}
}
void pintOP(stack_t **stack, unsigned int line_num)
{
	stack = stack;
	line_num = line_num;
}
void popOP(stack_t **stack, unsigned int line_num)
{
	stack = stack;
	line_num = line_num;
}
void swapOP(stack_t **stack, unsigned int line_num)
{
	stack = stack;
	line_num = line_num;
}
void addOP(stack_t **stack, unsigned int line_num)
{
	stack = stack;
	line_num = line_num;
}
