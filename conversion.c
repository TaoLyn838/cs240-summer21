/*
 *
 * project: hw1
 * name: Chengtao Lin
 * date: 6/1/20
 * file: conversion.c
 * notes:
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(char s[], int q);
void num2q(int num, char num_q[], int q);
int q2num(char num_q[], int q);
void f2b(float f, char fb[]);
float b2f(char fb[]);


int main(int argc, char * argv[])
{
	char num_q[10];
	int num = 2020;
	if (argc>1) num = atoi(argv[1]);
	/* this loop converts num into string num_q and print out */  
	for (int i=2; i<17; i++)
	{
		num2q(num, num_q, i);
		print(num_q, i);
		printf("       num: %d\n\n", q2num(num_q,i));
	}



	char fb[32];
	/* this loop converts f into binary string fb[] */      
	for (int i=-10;i<4;i++){
		float f = (float) pow(2,i); 
		f2b(f,fb);
		printf("pow(2,%2d)f: %g\n",i, f);
		print(fb,2);
		printf("pow(2,%2d)f: %g\n\n",i, b2f(fb));
	}

	float f = 127 + 0.1; 
	f2b(f,fb);
	printf("        f: %g\n", f);
	print(fb,2);
	printf("        f: %g\n\n", b2f(fb));
}




/* this function converts the integer num into a q_based string */
void num2q(int num, char num_q[], int q){
	num_q[0] = '\0'; //null
	char str[10], toAsc = 'A';
	int current = num;
		while(current != 0){
				int rem = current%q;
				if (q > 9 && rem >=10) {
					int remAsc = 10;
					rem -= remAsc;
					sprintf(str, "%c", toAsc+rem); //let reminder into a string str
					strcat(num_q, str); //string q[] add char from str each time
				} else {
					sprintf(str, "%d", rem); 
					strcat(num_q, str);
				}
				current = current/q;
		}
// reverse num_q
	char temp[strlen(num_q)-1];
	int j = 0;
		for (int i = strlen(num_q)-1; i >= 0; i--) {
			temp[j] = num_q[i];
			j++;
		}
		for (int numb = 0; numb < strlen(num_q); numb++) {
			num_q[numb] = temp[numb];
		}
}

/* this function converts a q_based string into an integer */
int q2num(char num_q[], int q){
	int total = 0;
	int q_size = strlen(num_q);
	for (int i = 0; i < strlen(num_q); i++) {
			int num = num_q[i]-'0';
			if (num >= 'A'-'0' && num <= 'Z'-'0') {
				num = (num_q[i]-'0')-7;
			}
			total += pow(q, --q_size)*num;
	}
	return total;
}


/* this function converts the float f into a binary string fb[]*/
void f2b(float f, char fb[]){
	fb[0] = '\0'; 
	int fInt = f; //remove f's reminder
	float fract = f - fInt; //get reminder
//////////////////////////	fraction part////////////////////
	char fracstr[25]="."; 
	float current = fract;
	int intV = 0;
	float floatV = fract;
	int bits = 8; 
	if (current == ((float)0)) {
		strcat(fracstr, "0");
	}	
	while (current != ((float)0) && bits > 0) {
		current = current * 2;
		intV = current;
		current = current - intV;
		floatV = current;
		if(intV == 0){
			strcat(fracstr,"0");
		} else if(intV == 1) {
			strcat(fracstr,"1");
		}
		bits--;
	}
///////////////////////////	int part////////////////////
	char intStr[10];
	int intCurrent = fInt;
	if (fInt == 0) {
		strcat(fb, "0");
	}
	while (intCurrent != 0) {
		int intRem = intCurrent%2;
		sprintf(intStr, "%d", intRem);
		strcat(fb, intStr);
		intCurrent /= 2;
	}
	char temp[strlen(fb)-1];
	int j = 0;
	for (int i = strlen(fb)-1; i >= 0; i--) {
		temp[j] = fb[i];
		j++;
	}
	for (int numb = 0; numb < strlen(fb); numb++) {
		fb[numb] = temp[numb];
	}
	strcat(fb, fracstr);
		
}

/* this function converts the binary string fb[] into a float */
float b2f(char fb[]){
	char intStr[20]="";
	char flStr[20]="";
	intStr[0] = '\0';
	flStr[0] = '\0';
	int i=0;
	int times=0;
	int intTotal=0;
	int fracTotal=0;
	int mul;
	for (i=0; i < strlen(fb); i++) {
		if (fb[i]=='.') {
			break;
		}
		intStr[i] = fb[i];
	}
	for (int j=i+1; j < strlen(fb); j++) {
		flStr[times] = fb[j];
		times++;
	}
	int size = strlen(intStr);
	for (int r=0; r<strlen(intStr); r++) {
		mul = intStr[r]-'0';
		intTotal += (pow(2, --size)*mul);
	}
	int size1 = strlen(flStr);
	for (int l=0; l<size1; l++) {
		mul = flStr[l]-'0';
		fracTotal += (pow(2, --size1)*mul);
	}
	char arr1[20], arr2[20];
	sprintf(arr1, "%d", intTotal);
	sprintf(arr2, "%d", fracTotal);
	strcat(arr1, ".");
	strcat(arr1, arr2);
	float numbers = atof(arr1);
	return numbers;
}

void bin_char(unsigned n, char s[]) 
{ 
	
	unsigned i, j=0; 
	for (i = 1 << 31; i > 0; i = i / 2) {
		s[j++] = (n & i)?  '1' : '0';
	}
	s[j] = 0;
}

void print(char s[], int q)
{
	printf(" %2d-string: ", q);
	for (int i=0;s[i]; i++){
		if (!((i)%4)&&i!=0) printf("|");
		printf("%c", s[i]);
	}
	printf("\n");
}



