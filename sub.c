#include "monty.h"

/**
 * sub - subtracts top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}
