#include "monty.h"

/**
 * _push -  adds a new node at the beginning
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = datax.push_value;
	if (*top)
	{
		new->next = *top;
		(*top)->prev = new;
	}
	else
		new->next = NULL;
	new->prev = NULL;
	*top = new;
}

/**
 * _pall -  prints all the elements of a dlistint_t list
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}
