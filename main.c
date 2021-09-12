#include "monty.h"

char *opGlobal[3] = {NULL, NULL, "stack"};
 
/**
 * @brief
 *
 *
 *
 */

int main(int argc, char **argv)
{
	FILE *fd;
	/*int i;
	stack_t *stack = NULL;
	char *inputstr[0] = { NULL };
	size_t buffersize = 0;*/

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Error: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*
	i = 0;
	while (getline(&(inputstr[i]), &buffersize, fd) > 0)
	{
		i++;
	}*/
	opcode_finder(fd);
	//frees
	fclose(fd);
	return (0);
}

/**
 * @brief
 *
 *
 *
 */

void opcode_exe(int line, stack_t **stack)
{
	int j, check = 0;

	instruction_t opStruct[] = {
		{"push", pushOP},
		{"pall", pallOP},
		{"pint", pintOP},
		{"pop", popOP},
		{"swap", swapOP},
		{"add", addOP},
		{"nop", NULL},
		{NULL, NULL}
	};

	for (j = 0; opStruct[j].opcode != NULL; j++)
	{
		if (strcmp(opStruct[j].opcode, opGlobal[0]) == 0)
		{
			if (opStruct[j].f)
			{
				opStruct[j].f(stack, line);
			}
			check = 1;
			break;
		}
	}
	if (check != 1)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line,
			opGlobal[0]);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief
 *
 *
 *
 */

void opcode_finder(FILE *fd)
{
	unsigned int line;
	int check = 0;
	char *opcode = NULL;
	size_t opLength = 0;
	stack_t *stack = NULL;

	for (line = 1;; line++)
	{
		check = getline(&opcode, &opLength, fd);
		if (check == EOF)
			break;
		opGlobal[0] = strtok(opcode, " \n");
		if (!opGlobal[0])
			opGlobal[0] = strtok(NULL, " \n");
		if (opGlobal[0][0] == '#')
			continue;
		opGlobal[1] = strtok(NULL, " \n");
		opcode_exe(line, &stack);
	}
	if (stack)
		free(stack); /* need to add function here for freeing the list */
	free(opcode);
}
