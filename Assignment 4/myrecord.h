// your program signature

#ifndef MYRECORD_H
#define MYRECORD_H

/*
 Define a structure named RECORD to hold a person's name of 20 characters and the score of float type.
 */
typedef struct {
	char name[20];
	float score;
} RECORD;

/*
 Define a structure named REPORT containing fields int count, float mean, float stddev (standard deviation).
 */
typedef struct {
	int count;
	float mean;
	float stddev;
} REPORT;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif
