/*
 ============================================================================
 Name        : polynomial.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * your program signature
 */

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

void display_polynomial(float p[], int n, float x) {
// your implementation

	for (int i; i < n; i++) {
		printf("%.2f*%.2f^%d", p[i], x, (n - (1 + i)));
		if (((n - (1 + i))) != 0) {
			printf("+");
		}
	}
	return;
}

float horner(float p[], int n, float x) {
// your implementation
	float answer = p[0];
	for (int i = 1; i < n; i++) {
		answer = answer * x + p[i];
	}
	return answer;
}

float bisection(float p[], int n, float a, float b) {
// your implementation

	float c;

	c = 0;

	while ((b - a) >= EPSILON) {
		c = (a + b) / 2;

		if (horner(p, n, c) == 0.0) {
			break;
		}

		else if ((horner(p, n, c)) * (horner(p, n, a)) < 0.0) {
			b = c;
		}

		else {
			a = c;

		}
	}

	return c;
}
