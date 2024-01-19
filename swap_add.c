#include "monty.h"
/**
 * swap_op - swaps the top two elements of the stack.
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void swap_op(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;
	int length = 0, temporary;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temporary = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temporary;
}
/**
 * add_op - adds the top two elements of the stack.
 * @stack: pointer to the stack's head
 * @l_number: line number in the Monty file
 * Return: no return
 */
void add_op(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;
	int length = 0, temporary;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l_number);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temporary = temp->n + temp->next->n;
	temp->next->n = temporary;
	*stack = temp->next;
	free(temp);
}
