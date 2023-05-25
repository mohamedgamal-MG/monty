// #include "monty.h"

// /**
//  * _pop - delete item at top of stack
//  * @stack: pointer to linked list stack
//  * @line_number: number of line opcode occurs on
//  */
// void _pop(stack_t **stack, unsigned int line_number)
// {
// 	if (*stack == NULL)
// 	{
// 		fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
// 		exit(EXIT_FAILURE);
// 	}
// 	delete_node(stack, 0);
// }


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pop - pops the very top element of the stack
 * @stack: stack given by main in start.c
 * @line_cnt: line number for error messages
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_cnt)
{
    stack_t *tmp = NULL;

    // Checking if the stack is empty
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
        exit(EXIT_FAILURE);
    }

    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;

    // Updating the previous pointer of the new top node
    if (!*stack)
        return; /* prevents errors cause next line might assign a NULL */
    (*stack)->prev = NULL;
}
