/*
 *
 * project: hw6
 * name: Chengtao LIn
 * date: 7/20/2020
 * file: hw6.c
 * note: Even something terminal will shows "make: *** [all] Segmentation fault: 11" when I
 * run make command, but merge_sortG and insertSortNodeI can be work which
 * integer variable. Moreover, merge_sortG doesn't work on 
 * double type variable. I do not why. 
 */


#include "hw6.h"



// Comparator for comparing two integer references (10 Points)
int comInt(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b) {
		return 1;
	} else if (*(int *)a > *(int *)b) {
		return -1;
	}
		return 0;
}

// Comparator for comparing two double references (10 Points)
int comDouble(const void *a, const void *b)
{
	if (*(double *)a < *(double *)b) {
		return 1;
	} else if (*(double *)a > *(double *)b) {
		return -1;
	}
	return 0;
}

// Merge sorting for ArrayG varible (30 Points)
// If the sorting is not merge sort, there will be no points earned for this function

void mergeG(ArrayG arr, ArrayG aux, int start, int mid, int end, int (*com)(const void *, const void *))
{
	for (int z = 0; z <= arr.size_n; ++z) {
			memcpy(aux.a + z * arr.size, arr.a + z * arr.size, arr.size_n);
		}
	int i = start, j = mid + 1;
	for (int k = start; k <= end; ++k) {
		if (i > mid) {
			memcpy(arr.a+k * arr.size, aux.a+j * arr.size, arr.size_n);
			break;
		}
		if(j > end) 
		{
			memcpy(arr.a+k * arr.size, aux.a+i * arr.size, arr.size_n);
			break;
			
		}
		int cmp = com(aux.a + i * arr.size, aux.a + j * arr.size);
		if (cmp > 0) {
			memcpy(arr.a + k * arr.size, aux.a + i * arr.size, arr.size_n);
			i++;
		} else {
			memcpy(arr.a + k * arr.size, aux.a + j * arr.size, arr.size_n);
			j++;
		}
	}
}

void mergeHelper (ArrayG arr, ArrayG aux, int start, int end, int (*com)(const void *, const void *)) {
	if (start >= end) return;
		int mid = start + (end - start) / 2;
		mergeHelper(arr, aux, start, mid, com);
		mergeHelper(arr, aux, mid + 1, end, com);
		mergeG(arr, aux, start, mid, end, com);
}

void merge_sortAG(ArrayG arr, int (*com)(const void *, const void *))
{
	ArrayG aux;
	aux.a = malloc(arr.size_n * arr.size);
	mergeHelper(arr, aux, 0, arr.size_n, com);
}



//Create a linkedlist from a ArrayG (20 points)

NodeI * newNodeI(ArrayG arr)
{
	NodeI *head = malloc(sizeof(NodeI));
	int *a = (int *) arr.a;
	head->pre = NULL;
	head->a = a[0];
	head->next = NULL;
	NodeI *p = head;
	for (int i = 1; i < arr.size_n; i++) {
		NodeI *node1 = malloc(sizeof(NodeI));
		node1->a = a[i];
		node1->pre = p;
		node1->next = NULL;
		p->next = node1; // to link head
		p = p->next;
	}
	return head;
}


// swim up the vaule of node p up to the linkedlist a until
// the value is bigger or equal to the vaule come before it or
// reaches to null

// swim() is used for insertSortNodeI (15 points)
NodeI * swim(NodeI *a, NodeI *p)
{
	int temp = p->a;
	p->a = a->a;
	a->a = temp;	
	return a;
}


// insertSort the linkedlist a.  (15 points)
// if you do not use insertion sort, then there will be no points earned.
NodeI* insertSortNodeI(NodeI *a) {
	NodeI *head = a;
	NodeI *sorted = a;
	a = a->next;
	while (a != NULL) {
		sorted = head;
		while (sorted != a) {
			if (sorted->a > a->a) {
				sorted = swim(sorted, a);
			} else {
				sorted = sorted->next;
			}
		}
		a = a->next;
	}
	return head;
}
