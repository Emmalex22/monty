#include "monty.h"
/**
 * pint_op - prints the top element of the stack
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void pint_op(stack_t **stack, unsigned int l_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop_op - removes the top element of the stack
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void pop_op(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	free(temp);
}
