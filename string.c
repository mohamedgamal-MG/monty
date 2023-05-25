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
 * set_mode - Sets the stack and queue modes.
 * @stack: Double pointer to the top of the stack.
 * @stack_mode_val: Value to set for stack mode
 * (non-zero for enabled, 0 for disabled).
 * @queue_mode_val: Value to set for queue mode
 * (non-zero for enabled, 0 for disabled).
 *
 * Description: This function updates
 * the values of the stack_mode and queue_mode
 * variables based on the provided parameters.
 * It allows enabling or disabling the
 * stack mode and queue mode in a centralized and reusable way.
 */
void set_mode(stack_t **stack, int stack_mode_val, int queue_mode_val)
{
	int queue_mode = 0;
	int stack_mode = 1;
	(void)stack;

	queue_mode += queue_mode_val;
	stack_mode += stack_mode_val;

	printf("queue_mode: %d\n", queue_mode);
	printf("stack_mode: %d\n", stack_mode);
}
