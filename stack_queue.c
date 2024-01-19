#include "monty.h"
/**
 * stack_op - sets the format of the data to a stack (LIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void stack_op(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	(void)head;
	(void)counter;
	montydata.stackflag = 0;
}
/**
 * queue_op - sets the format of the data to a queue (FIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void queue_op(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	(void)head;
	(void)counter;
	montydata.stackflag = 1;
}
/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *last_node;

	last_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (last_node)
	{
		while (last_node->next)
			last_node = last_node->next;
	}
	if (!last_node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
