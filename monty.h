#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int sq_flag;
/*--- Struct Definitions ---*/
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
 * struct instruction_s - opcoode and its function
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

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
char *parse(char *line);
instruct_func get_func(char *str);
void read_file(char *filename, stack_t **stack);
void _pall(stack_t **stack);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div_(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack);
void _rotr(stack_t **stack);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void free_list(stack_t *head);
int delete_node(stack_t **head, unsigned int index);
void error_exit(stack_t **stack);
int isnumber(char *str);
void free_stack(stack_t *stack);
int process_file(FILE *fp);
int execute_opcode(const char *opcode, stack_t **stack,
unsigned int line_number);
void set_mode(stack_t **stack, int stack_mode_val, int queue_mode_val);

#define MAX_LINE_LENGTH 1000
#endif
