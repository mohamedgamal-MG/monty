// #include "monty.h"
// /**
//  * f_add - adds the top two elements of the stack.
//  * @head: stack head
//  * @counter: line_number
//  * Return: no return
// */
// void add(stack_t **stack, unsigned int line_number)
// {
// 	if (*stack == NULL || (*stack)->next == NULL)
// 	{
// 		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
// 		exit(EXIT_FAILURE);
// 	}
// 	(*stack)->next->n += (*stack)->n;
// 	_pop(stack, line_number);
// }


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _add - adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
    int result;

    // Checking if the stack is empty or contains only one element
    if (!stack || !*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
        exit(EXIT_FAILURE);
    }

    // Performing the addition operation
    result = ((*stack)->next->n) + ((*stack)->n);

    // Removing the top node from the stack
    pop(stack, line_cnt); /* For top node */

    // Assigning the result to the new top node
    (*stack)->n = result;
}
