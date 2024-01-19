#include "monty.h"
/**
 * pchar_op - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void pchar_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	temp = *head;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", temp->n);
}
/**
 * pstr_op - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void pstr_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;

	temp = *head;

	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
