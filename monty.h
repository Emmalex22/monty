#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyinfo - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @l_content: line content
 * @stackflag: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct montyinfo
{
	char *arg;
	FILE *file;
	char *content;
	int stackflag;
} montyinfo;
extern montyinfo montydata;

void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void push_op(stack_t **head, unsigned int counter);
void pall_op(stack_t **head, unsigned int counter);
void add_op(stack_t **stack, unsigned int l_number);
void swap_op(stack_t **stack, unsigned int l_number);
void pop_op(stack_t **stack, unsigned int l_number);
void pint_op(stack_t **stack, unsigned int l_number);
void mynop(stack_t **head, unsigned int counter);
void div_op(stack_t **stack, unsigned int l_number);
void sub_op(stack_t **stack, unsigned int l_number);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void mod_op(stack_t **head, unsigned int counter);
void mul_op(stack_t **head, unsigned int counter);
void rotr_op(stack_t **head, __attribute__((unused)) unsigned int counter);
void rotl_op(stack_t **head, __attribute__((unused)) unsigned int counter);
void pstr_op(stack_t **head, unsigned int counter);
void pchar_op(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int n);
void queue_op(stack_t **head, __attribute__((unused)) unsigned int counter);
void stack_op(stack_t **head, __attribute__((unused)) unsigned int counter);


#endif
