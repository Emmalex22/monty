#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *current_head;

	current_head = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node\n");
		exit(EXIT_FAILURE);
	}
	if (current_head)
		current_head->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current_node;

	current_node = head;
	while (head)
	{
		current_node = head->next;
		free(head);
		head = current_node;
	}
}

