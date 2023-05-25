#include "monty.h"

/**
 * _swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}
