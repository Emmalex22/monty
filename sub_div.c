#include "monty.h"
/**
 * sub_op - subtraction
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void sub_op(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;
	int subtraction, nodes;

	temp = *stack;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	subtraction = temp->next->n - temp->n;
	temp->next->n = subtraction;
	*stack = temp->next;
	free(temp);
}
/**
 * div_op - divides the top two elements of the stack.
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void div_op(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;
	int len = 0, result;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n / temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
