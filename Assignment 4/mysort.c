/*
 ============================================================================
 Name        : sorting_a04.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// your program signature

#include "mysort.h"
/*
 Define an enumeration type named BOOLEAN with name false as 0 and true as 1.
 */
typedef enum boolean {
	false = 0, true = 1
} BOOLEAN;

/*
 This function tests if array a[n] is sorted in increasing order between index left and right, and returns true if yes, otherwise false.
 */
BOOLEAN is_sorted(int *a, int left, int right) {
// your implementation
	int i;
	for (i = 0; i < right; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}


/*
 This function swaps the values at referenced locations. It is an auxiliary function for the sorting functions.
 */
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

/*
 This function sorts the elements of int array *a from index left to right in increasing order, using the selection sort algorithm.
 */
void select_sort(int *a, int left, int right) {
// your implementation
	int i;
	int j;
	for (i = 0; i < right; i++) {
		left = i;
		for (j = i + 1; j < right + 1; j++) {
			if (a[j] < a[left])

				left = j;

		}
		swap(&a[left], &a[i]);
	}
}

/*
 This function sorts the elements of int array *a from index left to right in increasing order, using the quick sort algorithm.
 */
void quick_sort(int *a, int left, int right) {
// your implementation
	int i, j, pivot, temporary;

	if (left < right) {

		pivot = left;
		i = left;
		j = right;

		while (i < j) {

			while (a[i] <= a[pivot] && i < right)
				i++;

			while (a[j] > a[pivot])
				j--;

			if (i < j) {
				temporary = a[i];
				a[i] = a[j];
				a[j] = temporary;
			}
		}
		//int j = select_sort(a, left, right);
		//k = (left + right) / 2;
		//key = *(a + k);	//use *(a+k) as the pivot
		//split a[left..right] that element at j is equal to key
		//elements from left to j-1 are less or equal to key
		//elements from j+1 to right are bigger than key
		//temporary = a[pivot];
		//a[pivot] = a[j];
		//a[j] = temporary;
		swap(&a[pivot], &a[j]);
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}

