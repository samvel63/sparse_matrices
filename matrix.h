#ifndef _MATRIX_H_
#define _MATRIX_H_

//typedef double complex elem_type;
typedef int elem_type;

typedef struct {
	int n;
	int m;
	int entries;
	int *rowp;
	int *column;
	elem_type *elem;
} Matrix;

void create(Matrix *mat, int n, int m); // Create Matrix
void destroy(Matrix *mat); // Destroy Matrix
void insert(Matrix *mat, int i, int j, elem_type val); // Add element in array of notzero elements
elem_type get(Matrix *mat, int i, int j);
void print(Matrix *mat);
void CheckOnNullRows(Matrix *mat);

#endif