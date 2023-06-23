#include "monty.h"
void _push(stack_t **top, unsigned int line_number)
{
    stack_t *new;

    printf("Line: %d - Push value %d\n", line_number, datax.push_value);

    if (!top)
        return;
    new = malloc(sizeof(stack_t));
    if (!new)
        return;
    new->n = datax.push_value;
    if (*top)
    {
        new->next = *top;
        (*top)->prev = new;
    }
    else
        new->next = NULL;
    new->prev = NULL;
    *top = new;
}
void _pall(stack_t **top, unsigned int line_number)
{
    stack_t *current = *top;
    int i;

    printf("Line: %d - Pall exec!\n", line_number);

    for (i = 0; current; i++)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
size_t num_len(int num)
{
    int len = 0;

    if (!num)
        return (1);
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return len;
}
int main(int argc, char **argv)
{
    instruction_t ins[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL},
    };
    FILE *mfile;
    unsigned int line_num = 0;
    char line[100], *token;
    int i = 0, j = 0;

    printf("-- Number of arguments: %d\n", argc - 1);

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    printf("-- File name entered: %s\n", argv[1]);

    mfile = fopen(argv[1], "r");
    if (!mfile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), mfile) != NULL)
    {
        if (strlen(line) < 3)
            continue;
        line_num++;
        token = strtok(line, " \n");
        i = 0;
        while (token != NULL && i < 2)
        {
            if (i == 0) /*first part command first loop*/
                datax.opcode = token;
            if (strcmp(datax.opcode, "push") != 0) /*if opcode is not push break*/
                break;
            if (i == 1)
            {
                if (isdigit(token[0]) && strlen(token) == num_len(atoi(token)))
                    datax.push_value = atoi(token);
                else
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_num);
                    exit(EXIT_FAILURE);
                }
            }
            i++;
            token = strtok(NULL, " \n");
        }
        if (strcmp(datax.opcode, "push") == 0 && i == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_num);
            exit(EXIT_FAILURE);
        }
        for (j = 0; ins[j].opcode; j++)
        {
            if (strcmp(datax.opcode, ins[j].opcode) == 0)
            {
                ins[j].f(&datax.top, line_num);
                break;
            }
        }
        if (!ins[j].opcode)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_num, datax.opcode);
            exit(EXIT_FAILURE);
        }
    }

    printf("-- Total lines: %d\n", line_num);
    fclose(mfile);

    exit(EXIT_SUCCESS);
}
