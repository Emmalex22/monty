#include "monty.h"
/**
 * rotl_op - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotl_op(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new_head = (*head)->next;
	new_head->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = new_head;
}
/**
 * rotr_op - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotr_op(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last_node;

	last_node = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	last_node->next = *head;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	(*head)->prev = last_node;
	(*head) = last_node;
}
