/*
 ============================================================================
 Name        : matrix_.c
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
#include "matrix.h"

/*
 *  Displays the n by n matrix m in 2D style.
 */
void display_matrix(int *m, int n) {
	int *p = m, i, j;
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%4d", *p++);
	}
	printf("\n");
}

/*
 * Computes and returns the sum of all elements of the n by n matrix m.
 */
int sum(int *m, int n) {
	int *p = m, i, j, int_sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			int_sum += *p++;
	}
	return int_sum;
}

/*
 * Computes and returns if the n by n matrix m is a magic square.
 * returns 1 if true otherwise 0.
 * A square matrix is a magic square if the sum of every row, column, and diagonal is of the same value.
 *
 */

int is_magic_square(int *m, int n) {
	//add first row
	int int_sum = 0, remaining;
	int *pointer = m, i, j;

	for (i = 0; i < n; i++)
		int_sum += *pointer++;

	//check remaining rows sums
	for (i = 1; i < n; i++) {
		remaining = 0;
		for (j = 0; j < n; j++)
			remaining += *pointer++;
		if (int_sum != remaining)
			return 0;
	}

	pointer = m;
	//check column sum
	for (i = 0; i < n; i++) {
		remaining = 0;
		for (j = 0; j < n; j++)
			remaining += *(pointer + j * n + i);
		if (int_sum != remaining)
			return 0;
	}

	return 1;

	//check for left diagonal
	remaining = 0;
	for (i = 0; i < n; i++)
		remaining += *(pointer + i * n + i);
	if (int_sum != remaining)
		return 0;

	//check right diagonal
	remaining = 0;
	for (i = 0; i < n; i++)
		remaining += *(pointer + i * n + (n - 1 - i));
	if (int_sum != remaining)
		return 0;

	return 1;
 }

/*
 * Transposes the n by n matrix m1 and save the resulted matrix in m2.
 */
void transpose_matrix(int *m1, int *m2, int n) {
	int *pointer = m1, *pointer_2 = m2, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*pointer_2++ = *(pointer + n * j + i);
		}
	}

}

/*
 * Computes the matrix multiplication m1*m2 and saves the resulted matrix in m3.
 */
void multiply_matrix(int *m1, int *m2, int *m3, int n) {

	int *pointer_1 = m1, *pointer_2 = m2, *pointer_3 = m3, final = 0, k, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			final = 0;
			for (k = 0; k < n; k++) {
				final += (*(pointer_1 + n + k)) * (*(pointer_2 + k) + n);
			}
			*pointer_3++ = final;
		}
	}
}

