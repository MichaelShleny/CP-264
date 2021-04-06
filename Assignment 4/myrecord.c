/*
 ============================================================================
 Name        : data_processinga1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// your program signature
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100

/*
 This function converts a float score to a letter grade according to ranges
 S=[90, 100], A=[80, 90), B=[70, 80), C=[60, 70), D=[50,60), F=[0,50),
 and returns the letter grade.
 */
char letter_grade(float score) {

	char r = 'F';
	if (100 <= score && score >= 90)
		r = 'S';
	if ((90 <= score) && (score >= 80))
		r = 'A';
	if ((80 <= score) && (score >= 70))
		r = 'B';
	if ((70 <= score) && (score >= 60))
		r = 'C';
	if ((60 <= score) && (score >= 50))
		r = 'D';
	if ((50 <= score) && (score >= 0))
		r = 'F';
	return r;

}
/*
 This function imports data from file of name passed by filename, and stores all record entries
 in an array of RECORD dataset[], and returns the number of records read.
 */
int import_data(RECORD dataset[], char *filename) {

	FILE *fp = fopen(filename, "r");

	char delimiters[] = ",\n\r";

	char line[100];

	int i = 0;  // record counter
	char *token = NULL;

	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char *) strtok(line, delimiters);

		strcpy(dataset[i].name, token); //copy string char array
		token = (char *) strtok(NULL, delimiters);
		dataset[i].score = atof(token);  //convert string to float
		i++;

	}
	//fclose(fp);
	return i;
}

/*
 This function computes the average score, and standard deviation of the score values of
 dataset[], and returns the results by the RECORD type.
 It also outputs name and letter grade to file of name passed by filename, using format "%s,%c\n"
 */
REPORT report_data(RECORD dataset[], int count, char *filename) {

	FILE fp = fopen(filename, "w");

	REPORT report = { };

	report.count = count;
	float mean = 0;

	for (int i = 0; i < count; i++) {
		report.mean += dataset[i].score;
	}
	report.mean /= report.count;
	float stddev = 0;

	for (int i = 0; i < count; i++) {
		report.stddev += (dataset[i].score - mean) * (dataset[i].score - mean);

	}

	stddev = sqrt(stddev / report.count);

	return report;
}
