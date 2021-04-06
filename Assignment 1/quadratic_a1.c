/*
 ============================================================================
 Name        : quadratic_a1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>  // need this library for maths functions fabs() and sqrt()

#define EPSILON 0.000001
// or #define EPSILON 1e-6

int main() {
	//setvbuf(stdout, NULL, _IONBF, 0);
	//setvbuf(stderr, NULL, _IONBF, 0);

	float a, b, c, d, x1, x2;
	int inn;
	char temp;

	do {  // do-while for new input problem
		  // do-while loop to get correct input of three floating numbers,
		do {
			printf("\n");
			printf("Please enter the coefficients a,b,c\n");
			inn = scanf("%f,%f,%f", &a, &b, &c);

			if (inn != 3) {
				printf("input:Invalid input\n");
			} else
				break;

			do {  // flush the input buffer
				scanf("%c", &temp);
				if (temp == '\n')
					break;
			} while (1);

		} while (1);

		if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
			printf("input:quit\n");
			break;
		} else if (fabs(a) < EPSILON) {
			printf("input:not a quadratic equation\n");
		} else {

			d = b * b - 4 * a * c;  // compute the discriminant

			// your solution logic
			if (d < 0) {  //the equation has complex roots
				printf("The equation has 2 complex roots");
				printf("%6f%+6f", -b / (2 * a), -sqrt(-d) / (2 * a));

			} else if (d == 0) {  //the equation has two equal roots

				printf("The equation has two real roots");

				x1 = -b / (2 * a);
				printf("%.6f:", x1);

			} else { //The equation has distinct real roots
				printf("the equation has two distinct real roots");

				x1 = (-b + sqrt(d)) / (2 * a);
				x2 = (-b - sqrt(d)) / (2 * a);

				printf("\nx1: = %.6f\n", x1);
				printf("x2: = %.6f:", x2);

			}

		}
	} while (1);
	return 0;
}
