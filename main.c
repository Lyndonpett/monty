#include "monty.h"

char *opGlobal[3] = {NULL, NULL, "stack"};

/**
 * main - runs the monty
 *
 * @argc: the argument count
 * @argv: the individual arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	FILE *fd;

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
	opcode_finder(fd);
	fclose(fd);
	return (0);
}

/**
 * opcode_exe - executes the found opcode
 *
 * @stack: the list
 * @line: the line number
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
/**
 * opcode_finder - parses the file to find opcodes
 *
 * @fd: the file
 */
void opcode_finder(FILE *fd)
{
	unsigned int line = 0;
	int check = 0, j = 0;
	char *opcode = NULL;
	size_t opLength = 0;
	stack_t *stack = NULL;

	line = 1;
	while (line) /*itterating for each line in file*/
	{	/*read and store/malloc in check*/
		check = getline(&opcode, &opLength, fd);
		if (check == EOF) /*checks for End of File*/
			break;
		if (check == 1)
			continue;
		for (j = 0; opcode[0] != '\0'; j++) /*handles no input*/
		{
			if (opcode[j] == '\n' || check == 1)
				break;
			if (opcode[j] == ' ')
				check = 0;
			else
				check = 1;	}
		if (check == 0)
			continue;
		/*tokenize space and newlines*/
		opGlobal[0] = strtok(opcode, " \n");
		/*keep tokenizing for each line*/
		if (!opGlobal[0])
			opGlobal[0] = strtok(NULL, " \n");
		/*checks for # */
		if (opGlobal[0][0] == '#')/*checks for # */
			continue;
		/* tokenize the space between the argv's*/
		opGlobal[1] = strtok(NULL, " \n");
		/* run function executor */
		opcode_exe(&stack, line);
		line++; }
	if (stack)
		freeList(stack);
	free(opcode);
}
