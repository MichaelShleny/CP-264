/*
 ============================================================================
 Name        : mystring.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "mystring.h"
#define NULL 0

int str_length(char *s) {
// your implementation
	int i, count = 0;
	int length = strlen(s);

	for (i = 0; i < length; i++) {
		//checking if it is a character in the string
		if (i < length)

		count++;
	}
	return count;
}

int word_count(char *s) {
// your implementation
	int i;
	int count = 0;
	int length = strlen(s);
	for (i = 0; i < length - 1; i++) {
		if ((s[i] == ' ') && (s[i + 1] != ' '))
		{
			count++;
		}
	}
	return count;

}

void lower_case(char *s) {
// your implementation
	int i;
	int length = strlen(s);
	for (i = 0; i < length; i++) {
		s[i] = tolower(s[i]);
	}
}

void trim(char *s) {
// your implementation
	int i = 0;
	int j = 0;
	int length = strlen(s);
	char *temporary = (char *) malloc(sizeof(char) * length);
	int count = 0;

	//removing prefix white spaces
	while (s[i] == ' ')
	{
		i++;
	}

	//removing unnecessary spaces in between
	while (i < length - 1) {
		if (!(s[i] == ' ' && s[i + 1] == ' ')) {
			temporary[j] = s[i];
			j++;
		}
		i++;
	}
	temporary[j] = '\0';
	//copying temp to original string
	for (i = 0; i < strlen(temporary); i++) {
		s[i] = temporary[i];
	}
	s[i] = '\0';
}



