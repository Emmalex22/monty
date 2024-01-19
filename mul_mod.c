#include "monty.h"
/**
 * mul_op - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void mul_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, result;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
/**
 * mod_op - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void mod_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, result;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n % temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
