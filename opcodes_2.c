#include "monty.h"
int _isalpha(int c);
/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	/* if stack is more than 1 node, else free entire thing */
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		free(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int nline)
{
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	if (isascii(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", nline);
		exit(EXIT_FAILURE);
	}
	c = temp->n;
	printf("%c\n", c);
}
/**
 * pstr - prints a str from ascii starting from the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pstr(stack_t **stack, unsigned int nline)
{
	int idx = 0;
	char res[] = "";
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{	
		fprintf(stderr, "L%d: can't pchar, stack empty", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	/* starts at the top */
	while (temp)
	{
		if (temp->next == NULL)
			break;
		if (temp->n == 0)
			break;
		if (_isalpha(temp->n) == 0)
			break;
		c = temp->n;
		printf("%c", c);
		res[idx] += c;
		temp = temp->next;
		idx++;
	}
	printf("\n");	
}
