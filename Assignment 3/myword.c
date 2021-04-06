/*
 ============================================================================
 Name        : myword.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

void set_stopword(char *filename, char *stopwords[]) {
// your implementation, refer to class code example 22 -- csv file read with string value
	FILE *fp = fopen(filename, "r"); // this is at the very beginning to open the file

	char line[1000];
	char delimiters[] = ".,\n\t\r";
	char *token;
	int i;
	while (fgets(line, 1000, fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		while (token != NULL) {
			i = (int) (*token - 'a');
			strcat(stopwords[i], token);
			strcat(stopwords[i], ",");
			token = (char*) strtok(NULL, delimiters);
		}
	}
	fclose(fp); // at the very end to close the file
	return;
}

// this function check if word is a word in string str,
// returns 1 if yes, 0 otherwise
int contain_word(char *str, char *word) {
	if (str == NULL || word == NULL)
		return 0;
	// your code
	char temp[20] = { 0 };
	strcar(temp, ",");
	strcat(temp, word);
	strcat(temp, ",");

	if (strstr(str, temp)) { //use string.h function strstr too see if str contains a
		return 1;
	} else {
		return 0;
	}
}
 // this function check if the word is contained in directory stopwords[]
 // returns 1 if yes, 0 otherwise. It use function contain_word()
 int is_stopword(char *stopwords[], char *word) {
 // your code
	if (word == NULL || *word == '\0')
		return 0;
	else {
		return contain_word(stopwords[*word - 'a'], word);
	}
 }


 int process_word(char *filename, WORDSUMMARY *ws, char *stopwords[]) {
	const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
 // your implementation
	FILE * fp;
	fp = fopen("textdata.txt","r");
	char line[1000];
	char *word_token;
	
	while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
		ws -> line_count++;
		lower_case(line);
		trim(line);
		word_token = (char*)strtok(line,delimiters);
		
		while(word_token!=NULL){
			int i=(int)(*word_token - 'a');
			if (contain_word(stopwords[i], word_token)==0){
				strcpy(ws->word_array[i].word,word_token);
				ws->word_array[i].frequency = 1;
				ws->keyword_count++;
			}
			
			else{
				ws->word_array[i].frequency++;
			}
		}
		
		ws->word_count++;
		word_token = (char*)strtok(NULL,delimiters);	
	}

 }

 int save_to_file(char *filename, WORDSUMMARY *ws) {
 // your implementation
	FILE *fp = fopen(filename, 'w');
	fprintf("%s:%d\n", "line count", ws->line_count);
	fprintf("%s:%d\n", "word count", ws->word_count);
		fprintf("%s:%d\n", "non-common word count", ws->keyword_count);

	int i;
	for (i = 0; i < ws->keyword_count; i++) {
			WORD word = ws->word_array[i];
		fprintf("%s:%d\n", word.word, word.frequency);
	}
	fclose(fp);
	return 1;
}





