#include "monty.h"
/**
 * execute - Executes the opcode.
 * @content: Line content from Monty file.
 * @stack: Pointer to the stack's head.
 * @counter: Line counter in the Monty file.
 * @file: Pointer to Monty file.
 * Return: No return.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push_op}, {"pall", pall_op}, {"pint", pint_op},
		{"pop", pop_op}, {"swap", swap_op}, {"add", add_op},
		{"nop", mynop}, {"sub", sub_op},
		{"div", div_op}, {"mul", mul_op},
		{"mod", mod_op}, {"pchar", pchar_op},
		{"pstr", pstr_op}, {"rotl", rotl_op},
		{"rotr", rotr_op}, {"queue", queue_op},
		{"stack", stack_op}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	montydata.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
