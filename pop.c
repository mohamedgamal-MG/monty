#include "monty.h"

/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_node(stack, 0);
}
