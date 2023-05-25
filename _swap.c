#include "monty.h"

/**
  * _swap - Swaps the top two elements of a stack
  * @stack: Address of stack to be swaped
  * @line_number: Line number of opcode being executed
  */

void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	int data;

	/* Make sure node conatins more than 1 element */
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	/* Swap the data in the nodes */
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;

}
