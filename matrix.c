#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include "matrix.h"

void matrix_create(Matrix *mat, int n, int m)
{
	mat->n = n;
	mat->m = m;
	mat->entries = 0;
	mat->rowp = (int *)malloc((n + 1) * sizeof(int));
	mat->column = (int *)malloc(1 * sizeof(int));
	mat->elem = NULL;
	memset(mat->rowp, 0, (n + 1) * sizeof(int));
	mat->column[0] = 0;
}

void matrix_destroy(Matrix *mat)
{
	free(mat->rowp);
	free(mat->column);
	free(mat->elem);
}

void matrix_set(Matrix *mat, int i, int j, elem_type val)
{
	if (val == 0)
		return;
	for (int k = i + 1; k <= mat->n; ++k)
		mat->rowp[k]++;

	mat->entries++;
	mat->column = (int *)realloc(mat->column, (mat->entries + 1) * sizeof(int));
	mat->elem = (elem_type *)realloc(mat->elem, (mat->entries + 1) * sizeof(elem_type));
	mat->column[mat->entries - 1] = j;
	mat->elem[mat->entries - 1] = val;
}

void matrix_check_null_rows(Matrix *mat)
{
	for (int i = 0; i < mat->n; ++i) {
		if (mat->rowp[i] == mat->rowp[i + 1])
			mat->rowp[i] = -1;
	}
}

elem_type matrix_get(Matrix *mat, int i, int j)
{
	if (mat->rowp[i] == -1)
		return 0;
	for (int k = i + 1; k <= mat->n; ++k) {
		if (mat->rowp[k] != -1) {
			for (int l = mat->rowp[i]; l < mat->rowp[k]; ++l) {
				if (mat->column[l] == j) {
					return mat->elem[l];					
				}

			}
			break;
		}
	}
	return 0;
}

void matrix_print(Matrix *mat)
{
	for (int i = 0; i < mat->n; ++i) {
		for (int j = 0; j < mat->m; ++j) {
			elem_type num = matrix_get(mat, i, j);
			printf("(%.2lf + %.2lfi) ", creal(num), cimag(num));			
		}
		printf("\n");
	}
}