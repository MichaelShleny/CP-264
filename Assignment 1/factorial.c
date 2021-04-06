/*
 ============================================================================
 Name        : assignmentfactr.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
	int i = 1, n = 0, f = 1, prev, is_overflow = 0, count = 1;

	if (argc > 1) {
		n = atoi(args[1]);  // convert command line argument to an integer
		printf("factorial %d\n", n);

		if (n >= 1) {         // the conversion is successful
			// your solution logic code
			for (i = 1; i <= n; i++) {
				f *= i;

				if (i % 4 == 0) {

					printf("%11d\n", f);

				}

				if (i % 4 != 0) {

					printf("%11d", f);

				}
				if (i == 12) {
					printf("overflow: 13!");
					return 0;
				}
			}
			printf("\n%d!: %d", n, f);

		} else {
			printf("%s:invalid argument\n", args[1]);
		}
	} else {
		printf("no argument");
	}
	return 0;
}
