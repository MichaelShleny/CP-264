/*
 ============================================================================
 Name        : caseflip_a1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main() {
	//the following two lines are for Eclipse console none-buffered output, in case you use Eclipse to do your assignment
	//setvbuf(stdout, NULL, _IONBF, 0);
	//setvbuf(stderr, NULL, _IONBF, 0);
	char c = 0, temp;

	do {
		printf("\n");
		printf("Please enter a character\n");

		scanf("%c", &c); //this is to get  character input from keyboard

		do { // this loop is to get rid of additional characters in stdin buffer
			scanf("%c", &temp);
			if (temp == '\n')
				break;
		} while (1);

		// implement your program logic here
		if (c >= 97 && c <= 122)
			printf("%c:%d, %c", c, c, c - 32);

		else if (c >= 65 && c <= 90)
			printf("%c:%d, %c", c, c, c + 32);

		else if (c == 42) {
			printf(":quit");
		return 0;
		} else if (c > 122 || c < 97 || c > 90 || c < 65) {
			printf("Enter an ASCII value");
		}

		//QUIT THE PROGRAM OVER HERE


	} while (1);
	printf("%c:quit\n", c);

	return 0;
}



