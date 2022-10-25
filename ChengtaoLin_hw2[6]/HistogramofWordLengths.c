/*
 *
 * project: hw2
 * name: Chengtao Lin
 * date: 6/13/20
 * file: HistogramofWordLengths.c
 * notes: I write a founction call isNonAlpha(char)
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 27 /* max word length to consider */
#define ONESTSRT 4000 /* the capacity of one asterisk */

int isNonAlpha(char); /* check is character a non-alpha */

int main(int argc, char *argv[]) {
	int c;
	int table[MAX_LEN+1];
	int wordLen = 0;
	int currentLen = 0;
	int longestLen = 0;
	char longestW[MAX_LEN]="";
	///////// set up the table  /////////
	for (int i = 1; i <= MAX_LEN; ++i) {
		table[i] = 0;
	}
	
	while((c = getchar()) != EOF) {
		if (isNonAlpha(c) == 1) {
			longestW[currentLen]=c;
			++currentLen;
		} else {
			if (longestLen < currentLen) {
				longestLen = currentLen;
				longestW[0]='\0';
			}
			if (currentLen != 0 && currentLen <= MAX_LEN) {
				++table[currentLen];
			}
			currentLen=0;
		}
	}
	printf("%s\n\n", longestW);
	
	for (int j = 1; j <= MAX_LEN; j++) {
		printf(" %d %d", j, table[j]);
		if (table[j] != 0) {
			printf("%c%c", ' ', '*');
		}
		for (int count = 0; count < table[j]/ONESTSRT; count++) {
			putchar('*');
			}
		putchar('\n');
	}
}

int isNonAlpha(char c) {
	if ((!isalpha(c)) && (!isdigit(c))) { 
		return 0; // true
	}
	return 1;
}

