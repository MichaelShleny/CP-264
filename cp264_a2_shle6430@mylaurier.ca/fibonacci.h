/*
 ============================================================================
 Name        : fibonacci.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * your program signature
 */

extern int *la;  // global pointer variable to get local variable address

int* high_address = 0;
int* low_address = 0;

int iterative_fibonacci(int n) {

	if (&n < low_address)
		low_address = &n;

	int first = 0, second = 1, current;

	for (int i = 1; i < n; i++) {
		current = first + second;
		first = second;
		second = current;
	}
	return (second);

	// your implementation
}

int recursive_fibonacci(int n) {

	if (&n < low_address)
		low_address = &n;

	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	else
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
	// your implementation
}
