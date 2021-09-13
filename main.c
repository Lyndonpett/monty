#include "monty.h"

char *opGlobal[3] = { NULL, NULL, "stack" };

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

	if (argc != 2) /*checks if correct amount of argcs*/
	{
		dprintf(STDERR_FILENO, "Error: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r"); /*opens and reads file*/
	if (fd == NULL) /*checks if file is valid*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		fclose(fd);
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
 * @opcode: to keep opcode the same.
 * @fd: the file
 *
 */

void opcode_exe(stack_t **stack, unsigned int line, char *opcode, FILE *fd)
{
	int j, flag = 0;

	instruction_t opStruct[] = { { "push", pushOP }, { "pall", pallOP },
				     { "pint", pintOP }, { "pop", popOP },
				     { "swap", swapOP }, { "add", addOP },
				     { "nop", NULL },	 { NULL, NULL } };
	/* start itterating the struct */
	for (j = 0; opStruct[j].opcode != NULL; j++)
	{
		/* strcmp to match struct to global variable*/
		if (strcmp(opStruct[j].opcode, opGlobal[0]) == 0)
		{ /* get and run function*/
			opStruct[j].f(stack, line, opcode, fd);
			flag = 1;
			break;
		}
	}
	/* print error if no file is found*/
	if (flag != 1)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line,
			opGlobal[0]);
		free(opcode);
		freeList(*stack);
		fclose(fd);
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
	unsigned int line;
	int check = 0, j = 0;
	char *opcode = NULL;
	size_t opLength = 0;
	stack_t *stack = NULL;

	line = 1;
	while (line) /*itterating for each line in file*/
	{ /*read and store/malloc in check*/
		check = getline(&opcode, &opLength, fd);
		if (check == EOF) /*checks for End of File*/
			break;
		if (check > 1)
		{
			for (j = 0; opcode[0] != '\0'; j++) /*handles no input*/
			{
				if (opcode[j] == '\n' || check == 1)
					break;
				if (opcode[j] == ' ' || opcode[j] == '\t')
					check = 0;
				else
					check = 1;	}
			if (check == 0)
				continue;
			/*tokenize space and newlines*/
			opGlobal[0] = strtok(opcode, " \n\t");
			/*keep tokenizing for each line*/
			if (!opGlobal[0])
				opGlobal[0] = strtok(NULL, " \n\t");
			if (opGlobal[0][0] == '#')
				continue;
			/* tokenize the space between the argv's*/
			opGlobal[1] = strtok(NULL, " \n\t");
			/* run function executor */
			opcode_exe(&stack, line, opcode, fd);
		}
		line++;	}
	if (stack)
		freeList(stack);
	free(opcode);
}
