#ifndef HW5_H
#define HW5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <getopt.h>
#ifndef TEST_FILE
#define TEST_FILE(f,s,s1)     \
        if (NULL==f){        \
            fprintf(stderr, "%s: can't open %s\n", s,s1);\
            exit(1);}
#endif

typedef struct
{
    double x,y;
} Point;

Point *createData(int seed,int n);

/*
    Add your functions declerations here
*/

typedef struct polarAngle
{
	int i;
	double angle;
}PolarAngle;

void LargestY(Point *, int);
int *sortAngle(Point *, int);
void convexHull(Point *, int *, int);

#endif
