#include "monty.h"
/**
 * _pall - prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
