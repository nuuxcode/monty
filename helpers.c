#include "monty.h"
/**
 * openfile -  open file
 * @filename: file name
 * Return: FILE
 */
FILE *openfile(char *filename)
{
	FILE *mfile;

	mfile = fopen(filename, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}

/**
 * num_len -  count how many charachter in number
 * @num: number
 * Return: the number lentgh
 */
size_t num_len(int num)
{
	int len = 0;

	if (!num)
		return (1);
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
 * verify_number -  verify is number for push opcode
 * is valid or not
 * @token: token string
 * Return: none
 */
void verify_number(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		datax.push_value = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack -  frees stack
 * @top: head of double list
 * Return: none
 */
void free_stack(stack_t *top)
{
	stack_t *nav, *nav2;

	nav = top;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	datax.top = NULL;
	fclose(datax.mfile);
}
