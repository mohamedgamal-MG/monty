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
Expand All
	@@ -17,12 +20,12 @@
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
Expand All
	@@ -31,39 +34,35 @@ typedef struct stack_s
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
void _pall(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void free_list(stack_t *head);
int delete_node(stack_t **head, unsigned int index);
void error_exit(stack_t **stack);
int isnumber(char *str);
size_t getline (char **string, size_t *n, FILE *stream);
void free_stack(stack_t *stack);
#endif
