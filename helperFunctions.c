#include "monty.h"
/**
 * add_node - adds a new node at the beginning of a list.
 *
 * @head: the head.
 * @n: the element.
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 * Return: address of new node or NULL on failure.
 */

stack_t *add_node(stack_t **head, const int n, char *opcode, FILE *fd)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(new);
		freeList(*head);
		free(opcode);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	return (new);
}
/**
 * pallHELPER - prints a list.
 *
 * @h: the starting node.
 *
 * Return: the count of elements printed.
 */

size_t pallHELPER(const stack_t *h)
{
	size_t count = 0;
	const stack_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * freeList - frees a list.
 *
 * @head: the head.
 *
 * Return: void.
 */

void freeList(stack_t *head)
{
	stack_t *freed = head;

	while (freed != NULL)
	{
		if (freed->prev != NULL)
		{
			free(freed->prev);
		}
		if (freed->next == NULL)
		{
			free(freed);
			return;
		}
		else
		{
			freed = freed->next;
		}
	}
}
