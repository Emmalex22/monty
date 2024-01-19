#include "monty.h"
/**
 * push_op - Add node to the stack or queue based on montydata.stackflag
 * @head: Pointer to the head of the stack/queue
 * @counter: Line number in the Monty bytecode file
 * Return: No return value
 */
void push_op(stack_t **head, unsigned int counter)
{
	int I, j = 0, stackflag = 0;

	if (montydata.arg)
	{
		if (montydata.arg[0] == '-')
			j++;

		for (; montydata.arg[j] != '\0'; j++)
		{
			if (montydata.arg[j] > 57 || montydata.arg[j] < 48)
				stackflag = 1;
		}

		if (stackflag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(montydata.file);
			free(montydata.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(montydata.file);
		free(montydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	I = atoi(montydata.arg);

	if (montydata.stackflag == 0)
		addnode(head, I);
	else
		addqueue(head, I);
}
/**
 * pall_op - prints all contents of the stack
 * @head: stack head
 * @counter: not used
 *  Description: This function prints the integer values of all elements
 * Return: no return
 */
void pall_op(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;
	temp = *head;
	if (temp == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
