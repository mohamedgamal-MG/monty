#include "monty.h"
/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
 * _rotl - rotates the list left
 * @stack: pointer to the top of the stack
 *
 */
void _rotl(stack_t **stack)
{
	stack_t *first = *stack;
	stack_t *second = (*stack)->next;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (first->next != NULL)
			first = first->next;

		first->next = *stack;
		(*stack)->prev = first;
		*stack = second;
		second->prev = NULL;
		first->next->next = NULL;
	}
}

/**
 * _rotr - rotates the list right
 * @stack: pointer to the top of the stack
 *
 */
void _rotr(stack_t **stack)
{
	stack_t *last = *stack;
	stack_t *second_last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
			last = last->next;

		second_last = last->prev;

		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;

		if (second_last != NULL)
			second_last->next = NULL;
	}
}
