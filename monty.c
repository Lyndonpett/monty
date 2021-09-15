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
	int i, j;

	if (!opGlobal[1]) /*checks if theres a second arg */
	{
		errorEXIT(stack, line_num, opcode, fd);
	} /* itterate string to check for character*/
	for (j = 0; opGlobal[1][j] != '\0'; j++)
	{
		if (isalpha(opGlobal[1][j]) != 0)
		{
			errorEXIT(stack, line_num, opcode, fd);
		}
	} /* handles 0 edgecase so atoi passes */
	if (strcmp(opGlobal[1], "0") == 0 || strcmp(opGlobal[1], "-0") == 0)
	{
		i = 0;
	}
	else
	{ /* atoi number */
		i = atoi(opGlobal[1]);
		/* checks if atoi failed */
		if (i == 0)
		{
			errorEXIT(stack, line_num, opcode, fd);
		}
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
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
			line_num);
		freeList(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	printf("%i\n", tmp->n);
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
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			line_num);
		freeList(*stack);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = NULL;
	}
	if (tmp == *stack)
	{
		if ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}
		else
		{
			*stack = NULL;
		}
	}
	free(tmp);
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
	stack_t *tmp, *cog;
	int n;

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
	n = tmp->n;
	tmp->n = cog->n;
	cog->n = n;
}
