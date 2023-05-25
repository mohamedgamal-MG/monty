#include "monty.h"

/**
  * pall - Function that prints all the values of the stack
  * @stack: The adress of the stack to print
  * @line_number: The line number of the opcode being executed
  */

void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	int counter = 0;
	(void) line_num;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		counter++;
		temp = temp->next;
	}



}
