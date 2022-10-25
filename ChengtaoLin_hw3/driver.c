/*
 * 
 *
 * project: hw3
 * name:Chengtao Lin
 * date: 6/20/20
 * file: driver.c
 * notes: 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This is the driver test for testing your implementation
 * Do not modify the code below
 */

void str_test();
void num_test();
void comment_test();


// 20 points
// Write the function any(s1,s2) , which
// returns the first location in a string s1 where any
// character from the
// string s2 occurs, or -1 if s1 contains no characters
// from s2 . (The standard library function strpbrk does 
// the same job but  returns a pointer to the location.)

int any(char s1[], char s2[]){
	int hasNext = 1, find = -1;
	int i, j;
	for (i = 0; s1[i] != '\0' && (hasNext); i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				find = i;
				hasNext = 0;
			}
		}
	}
	return find;
}

// 20 points

// Write squeeze(s1,s2)
// that deletes each character in s1 that matches any character 
// in the string s2 .

void squeeze(char s1[], char s2[]){
	int i, j, inde;
	for (i = 0; s2[i] != '\0'; i++) { // search s2 times
		inde = 0;
		for (j = 0; s1[j] != '\0'; j++) {
			if (s1[j] != s2[i]) {
				s1[inde++] = s1[j];
			}
		}
		s1[inde] = '\0';
	}
}

// 20 points

// Write a function rightrot(x,n) that returns the 
// value of the integer x rotated to the right by n positions.


unsigned rightrot(unsigned x, int n){
	int wordLen;
	unsigned uns = (unsigned) ~0; 
	unsigned bits;
	for (wordLen = 1; (uns = uns>>1) > 0; wordLen++);
	bits = x << (wordLen - n);
	x = x >> n;
	x = x | bits;
	return x;
}


// 20 points

// Write a function invert(x,p,n) that returns x with 
// the n bits that begin at position p inverted (i.e., 1 changed
// into 0 and vice versa), leaving the others unchanged.

//  XOR operator ^:  x ^  0  keeps x intact
//                :  x ^ ~0  equivalent to ~x  filps all bits of x

unsigned invert(unsigned x, int p, int n){
	return x ^ (~(~0 << n) << (p + 1 - n));
}




int main(int argc, char * argv[]){   

	str_test(argv[1]);
	num_test(argv[2]);

  return 0;
}


void str_test(char *str){

	FILE *file_str;
	file_str = fopen(str, "r");

	char s[100], s1[50], s2[50];
	int i=0,j=0;
	while ((fgets(s,100, file_str)) != NULL){

		if (s[0]=='\n' || s[0]=='#') continue;
		
		while (s[i] != ','){
			s1[i] = s[i];
			i++;
		}
		s1[i++] = 0;

		while (s[i] != '\n' && s[i] != EOF){
			s2[j++] = s[i++];
		}
		s2[j] = 0;
		printf("s1: %s\t s2: %s\t Postion: %d\t",s1,s2,any(s1,s2));
		squeeze(s1,s2);
		printf("Squeezed s1: %s\n", s1);

		i = j = 0;

	}


	 fclose(file_str);
}


void num_test(char *numfile){

	printf("\n");

	FILE *file_num;
	file_num = fopen(numfile, "r");
	char s[100];
	unsigned int num, n, p;
	while ((fgets(s,100, file_num)) != NULL){

		if (s[0]=='\n' || s[0]=='#') continue;
		sscanf(s,"%u,%u,%u",&num, &n, &p);
		printf("num is: %u\t right rotate %u bits is: %u \t" 
				"invert at %u with %u right_ajusted bits is: %u\n",
				 num,n, rightrot(num,n),p,n, invert(num,p,n));

	}

	 fclose(file_num);
}
