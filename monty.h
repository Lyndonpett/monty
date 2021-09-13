#ifndef MONTY_H
#define MONTY_H
/* LIBRARIES */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

extern char *opGlobal[];

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ProtoTypes */
int main(int argc, char **argv);
void opcode_exe(stack_t **stack, int line);
void opcode_finder(FILE *fd);
void pushOP(stack_t **stack, unsigned int line_num);
void pallOP(stack_t **stack, unsigned int line_num);
void pintOP(stack_t **stack, unsigned int line_num);
void popOP(stack_t **stack, unsigned int line_num);
void swapOP(stack_t **stack, unsigned int line_num);
void addOP(stack_t **stack, unsigned int line_num);
stack_t *add_node(stack_t **head, const int n);
size_t pallHELPER(const stack_t *h);





#endif /* MONTY_H */
