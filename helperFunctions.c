#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a list.
 *
 * @head: the head.
 * @n: the element.
 *
 * Return: address of new node or NULL on failure.
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (NULL);
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
 * print_dlistint - prints a list.
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