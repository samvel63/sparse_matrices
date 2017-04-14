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

void matrix_create(Matrix *mat, int n, int m);
void matrix_destroy(Matrix *mat);
void matrix_set(Matrix *mat, int i, int j, elem_type val);
void matrix_check_null_rows(Matrix *mat);
elem_type matrix_get(Matrix *mat, int i, int j);
void matrix_print(Matrix *mat);

#endif