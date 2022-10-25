#include <stdio.h>
#include "hw5.h"

Point *createData(int seed, int n) {
	// create csv file points
	FILE *f = fopen("points.csv", "w");
	// check NULL illegality case 
	TEST_FILE(f, "createData", "points");
	Point *p; int i;
	srand48(seed);
	p = calloc(n, sizeof(Point));
	for (i = 0; i < n; i++) {
		p[i].x = drand48();  // set random between 0 and 1
		p[i].y = drand48(); 
		fprintf(f, "%f,%f", p[i].x, p[i].y);
	}
	fclose(f);
	return p;
}

// hepler methods

int cmpLargestY(Point *p, int size) {
	int i, largestY = 0;
	for (i = 1; i < size; i++) {
		if (p[i].y > p[largestY].y) {
			largestY = i;
		}
	}
	return largestY;
}

int cmpQuickS_Angle(const void *p, const void *q) {
	if (((PolarAngle*) p)->angle > ((PolarAngle*) q)->angle) {
		return 1;
	} else if (((PolarAngle*) p)->angle < ((PolarAngle*) q)->angle) {
		return -1;
	}
	return 0;
}

PolarAngle *sortAngleHelper(Point *p, size_t n, int size, int largest) {
	PolarAngle *angles = calloc(size, sizeof(n));
	int i;
	double x, y, r;
	for (i = 0; i < size; i++) {
		if (i != largest) {
			angles[i].i = i;
			x = p[i].x - p[largest].x;
			y = p[i].y - p[largest].y;
			r = sqrt((x * x) + (y * y));
			angles[i].angle = x / r;
		} else {
			angles[i].i = i;
		angles[i].angle = -1.0;

		} 
	} 
	return angles;
}

// main methods

void LargestY(Point *p, int n) {
	int indexLY = cmpLargestY(p, n);
	printf("The point with the largest y-coordinate is: (%g,%g)\n", \
		p[indexLY].x, p[indexLY].y);
}

int *sortAngle(Point *p, int n) {
	FILE *f = fopen("sortedPoints.csv", "w");
	TEST_FILE(f,"sortAngle","sortedPoints.csv");
	int *indexes, i;
	indexes = malloc(n * sizeof(int));
	int largest = cmpLargestY(p, n);
	PolarAngle *a = sortAngleHelper(p, sizeof(PolarAngle), n, largest);
	qsort(a, n, sizeof(PolarAngle), cmpQuickS_Angle);
	for (i = 0;i < n; i++){
			indexes[i] = a[i].i;
			fprintf(f, "%f,%f\n",p[indexes[i]].x,p[indexes[i]].y);
			printf("%d\t%g\n",a[i].i,a[i].angle);
	}
		fclose(f);
		return indexes;
}

void convexHull(Point* p,int *indexes,int n){
	FILE *f = fopen("pointsCon.csv", "w");
	TEST_FILE(f,"convexHull","pointsCon.csv");
	int stack[n], top=2, i; 
	double cmp;
	Point *prev,*curr,*next;
	memcpy(stack, indexes, 3 * sizeof(int));
	i = 3;
	while (i < n + 1) {		
		prev = &p[stack[top-1]];
		curr = &p[stack[top]];
		next = &p[indexes[i % n]];
		cmp = (curr->x - prev->x) * (next->y - prev->y) 
		-(next->x - prev->x) * (curr->y - prev->y);
		if (cmp >= 0.0) {
			stack[++top] = indexes[i++ % n]; 
		} else {
			top--;
		}
	}
	printf("There are %d points in the stack\n", top);
	for (int i=0;i < top;i++){
		fprintf(f, "%f,%f\n",p[stack[i]].x,p[stack[i]].y);
		printf("%f6\t%g\n",p[stack[i]].x,p[stack[i]].y);
	}
	fclose(f);
}