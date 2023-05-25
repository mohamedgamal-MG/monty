// #include "monty.h"

// /**
//  * div - divide top of stack and second top of stack
//  * @stack: pointer to linked list stack
//  * @line_number: number of line opcode occurs on
//  */
// void _div(stack_t **stack, unsigned int line_number)
// {
// 	if (*stack == NULL || (*stack)->next == NULL)
// 	{
// 		fprintf(stderr,"L%d: can't div, stack too short\n", line_number);
// 		exit(EXIT_FAILURE);
// 	}
// 	if ((*stack)->n == 0)
// 	{
// 		fprintf(stderr,"L%d: division by zero\n", line_number);
// 		exit(EXIT_FAILURE);
// 	}
// 	(*stack)->next->n /= (*stack)->n;
// 	_pop(stack, line_number);
// }



#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _div - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
    int result;

    // Checking if the stack is empty or contains only one element
    if (!stack || !*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
        exit(EXIT_FAILURE);
    }

    // Checking if division by zero is attempted
    if (((*stack)->n) == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_cnt);
        exit(EXIT_FAILURE);
    }

    // Performing the division operation
    result = ((*stack)->next->n) / ((*stack)->n);

    // Removing the top node from the stack
    pop(stack, line_cnt); /* For top node */

    // Assigning the result to the new top node
    (*stack)->n = result;
}
