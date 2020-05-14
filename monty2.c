#include "monty.h"
/**
 * swap - swaps the top two elements
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *next;
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	next = (*stack)->next;
	temp = head->n;
	head->n = next->n;
	next->n = temp;
}

/**
 * add - add the top two elements and pops the top and stores it in the new top
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void add(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * nop - does nothing
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * check_num - Checks if a string is a number.
 *
 * @num: Pointer to the supposed number string.
 *
 * Return: 0 if the string contains a non-number character, otherwise 1.
 */
char check_num(char *num)
{
	unsigned int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
	}
	return (1);
}
