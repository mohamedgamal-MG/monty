#include "monty.h"
int sq_flag = 0;
/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Description: The main function reads the Monty byte code file,
 * executes the corresponding opcodes, and handles errors.
 * It creates and initializes the stack, reads each line of the file,
 * tokenizes the line to extract the opcode, and executes the opcode function.
 * If an unknown opcode is encountered or an error occurs,
 * an error message is printed and the program exits with EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE otherwise.
 */

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (process_file(fp) == -1)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	return EXIT_SUCCESS;
}


