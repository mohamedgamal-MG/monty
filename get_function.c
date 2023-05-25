#include "monty.h"

/**
  * get_func - Get the opcode's corresponding function
  * @s: The opcode to get a function for
  *
  * Return: A pointer to the corresponding function
  */

void (*get_func(char *s))(stack_t **head, unsigned int line_num)
{
	int i = 0;
	instruction_t opcodes[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"add", _add},
				{"swap", _swap},
				{"nop", _nop},
				{"sub", _sub},
				{"mul", _mul},
				{"div", _div},
				{"mod", _mod}
	};

	while (i < 11)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}

	return (NULL);
}
