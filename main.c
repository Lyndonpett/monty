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
	unsigned int line;
	int check = 0, j;
	char *opcode = NULL;
	size_t opLength = 0;
	stack_t *stack = NULL;

	if (argc != 2)/*checks if correct amount of argcs*/
	{
		dprintf(STDERR_FILENO, "Error: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");/*opens and reads file*/
	if (fd == NULL)/*checks if file is valid*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = 1;
	while (line) /*itterating for each line in file*/
	{
		check = getline(&opcode, &opLength, fd);/*read and store/malloc in check*/
		if (check == EOF)/*checks for End of File*/
			break;
		for (j = 0; opcode[0] != '\0'; j++) /*handles no input*/
			if (opcode[j] == '\n' || check == 1)
				break;
		opGlobal[0] = strtok(opcode, " \n");/*tokenize space and newlines*/
		if (!opGlobal[0])/*keep tokenizing for each line*/
			opGlobal[0] = strtok(NULL, " \n");
		if (opGlobal[0][0] == '#')/*checks for # */
			continue;
		opGlobal[1] = strtok(NULL, " \n");/* tokenize the space between the argv's*/
		opcode_exe(&stack, line);/* run function executor */
		line++; }
	if (stack)
		free(stack); /* need to add function here for freeing the list */
	free(opcode);
	fclose(fd);
	return (0);
}

/**
 * @brief
 *
 *
 *
 */

void opcode_exe(stack_t **stack, int line)
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
	/* start itterating the struct */
	for (j = 0; opStruct[j].opcode != NULL; j++)
	{	/* strcmp to match struct to global variable*/
		if (strcmp(opStruct[j].opcode, opGlobal[0]) == 0)
		{	/* get and run function*/
			opStruct[j].f(stack, line);
			check = 1;
			break;
		}
	}
	/* print error if no file is found*/
	if (check != 1)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line,
			opGlobal[0]);
		exit(EXIT_FAILURE);
	}
}
