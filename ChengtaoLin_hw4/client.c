/* 
* Author : CHengtao Lin
* Description: homework4
*	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ** fgetLines(FILE* f, int *nl)
{
	int i, col;
	int line = *nl;
	char **lines = (char **)malloc(line * sizeof(char *));
	for (i = 0; i < line; i++) {
		lines[i] = (char *)malloc(10000 * sizeof(char));
	}
	col = 0;
	int row = 0;
	char c;
	while (((c = fgetc(f)) != EOF) && (row < line)) {	
		if (c == '\n') {
			lines[row][col] = '\0'; // reset the size
			row++;
			col = 0;
		} else {
			lines[row][col] = c;
			col++;
		}
	}
	return lines;
}




char ** sgetWords(char *line, int *nw)
{
	int i;
	int totalWords = *nw;
	char ** words = (char **)malloc(totalWords * sizeof(char *));
	for (i = 0; i < totalWords; i++) {
		words[i] = (char *)malloc(10000 * sizeof(char));
		}
	int row = 0, col = 0;
	for (i = 0; line[i] != '\0'; i++) {
		if (line[i] == ',') {
			words[row][col] = '\0';
			row++;
			col = 0;
			
		}
		if (isalnum(line[i])) {
			words[row][col] = line[i];
			col++;
		}
	}
	return words;
}

char* cPrefix(char **words, int nw)
{
	if (nw == 0) { // check numbers of words
		char * zeroCase = (char *)calloc(1, sizeof(char));
		return zeroCase;
	}
	int row, col, hasPre;
	col = 0;
	hasPre = 1; 
	char checkPre = words[0][col];
	while (checkPre != '\0') {
		for (row = 1; row < nw; row++) {
			if (words[row][col] != checkPre) {
				hasPre = 0;
				break;
			}
		}
		if (hasPre != 0) {
			checkPre = words[0][col++];
		}
	}
	words[0][col] = '\0';
	return words[0];
}




/*
	Do not modify the main function when submit.
	You can modify it when doing your homework.
*/

int main(int argc, char *argv[])
{

	// Get test file name from commandline or default to test.txt
	char *fs = argc>2 ? argv[1] : "test.txt";
	FILE *f = fopen(fs,"r");	
	
	// Read each line into lines, nl is the number of lines
	
	int nl=0, nw=0;
	char **lines = fgetLines(f, &nl);

	for (int i = 0; i < nl; ++i)
	{	
		/*
			Read each word into words, nw is the number of words for each line
			words should have separate memory than lines[i]
		*/		
		nw=0;
		char **words= sgetWords(lines[i], &nw);
		if (nw==0) continue;
		
		printf("\nTotal: %d\n", nw);
		for (int i = 0; i < nw; ++i) printf("%s, ", words[i]);
		printf("\nThe common prefix is: %s\n", cPrefix(words,nw));
		
		for (int i = 0; i < nw; ++i) free(words[i]);		
		free(words);

	}

	for (int i = 0; i < nl; ++i) free(lines[i]);		
	free(lines);
	fclose(f);



	return 0;
}
