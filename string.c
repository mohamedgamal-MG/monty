#include "monty.h"

/**
 * pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr,"L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	val = temp->n;

	if (!isprint(val))
	{
		fprintf(stderr,"L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}
/**
 * pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *temp;
	int val;

	temp = *stack;

	while (temp != NULL)
	{
		val = temp->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * stack - sets sq_flag to stack
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	sq_flag = 0;
}
/**
 * queue - sets sq_flag to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void queue(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number)
{
	sq_flag = 1;
}
