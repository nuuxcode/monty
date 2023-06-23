#include "monty.h"

/**
 * exec - exec opcode
 * Return: none
 */
void exec(void)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(datax.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&datax.top, datax.line_num);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				datax.line_num, datax.opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * remove_spaces - remove spaces
 * @str: string
 * Return: new string
 */
char *remove_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}

/**
 * main -  count how many charachter in number
 * @argc: number
 * @argv: number
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	FILE *mfile;
	char line[100], *token;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		fflush(stderr);
		exit(EXIT_FAILURE);
	}
	mfile = openfile(argv[1]);
	while (fgets(line, sizeof(line), mfile) != NULL)
	{
		if (strlen(remove_spaces(line)) < 3)
			continue;
		datax.line_num++;
		token = strtok(line, " \n");
		i = 0;
		while (token != NULL && i < 2)
		{
			if (i == 0) /*first part command first loop*/
				datax.opcode = token;
			if (strcmp(datax.opcode, "push") != 0) /*if opcode is not push break*/
				break;
			if (i == 1)
				verify_number(token);
			i++;
			token = strtok(NULL, " \n");
		}
		if (strcmp(datax.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
			fflush(stderr);
			exit(EXIT_FAILURE);
		}
		exec();
	}
	fclose(mfile);
	free_stack(datax.top);
	exit(EXIT_SUCCESS);
}
