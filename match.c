#include "monty.h"

/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line contents and line number
 *
 * Return: pointer to the matching function
 */
void (*get_op_func(line_t line))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addop},
		{"sub", subop},
		{"div", divop},
		{"mul", mulop},
		{"mod", modop},
		{"nop", nop},
		{"pchar", pchar},
		{"rotl", rotl},
		{NULL, NULL}
	};

	if (comment_check(line))
		return (nop);

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line, ops, i);
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	printf("L%d: unknown instruction %s\n", line.number, line.content[0]);
	free(line.content);
	exit(EXIT_FAILURE);
}
