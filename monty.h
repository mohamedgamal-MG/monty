#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void add(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
instruct_func get_func(char *str);
stack_t *add_node(stack_t **head, const int n);
int delete_node(stack_t **head, unsigned int index);
stack_t *add_node_end(stack_t **head, const int n);
void free_list(stack_t *head);
int main(int ac, char **av);
int sq_flag = 0;
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _nop(__attribute__ ((unused))stack_t **stack,
	  __attribute__ ((unused))unsigned int line_number);
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
char *parse(char *line);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void read_file(char *filename, stack_t **stack);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number);
void queue(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void error_exit(stack_t **stack);
int isnumber(char *str);
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number);

