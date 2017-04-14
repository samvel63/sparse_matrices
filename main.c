#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include "matrix.h"

int main(void)
{
	int n, m;
	double x = 0.0, y = 0.0;
	Matrix mat;
	scanf("%d %d", &n, &m);
    matrix_create(&mat, n, m);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		scanf("%lf %lf", &x, &y);
    		elem_type val = x + y * I;
    		matrix_set(&mat, i, j, val);
    	}
    }
    matrix_check_null_rows(&mat);
    printf("\n\n");
    for (int i = 0; i < mat.entries; ++i)
    	printf("column=%d, val=(%.2lf + %.2lfi)\n", mat.column[i], creal(mat.elem[i]), cimag(mat.elem[i]));

    for (int i = 0; i <= mat.n; ++i)
    	printf("%d ", mat.rowp[i]);
    printf("\n");
    matrix_print(&mat);

    matrix_destroy(&mat);	
    return 0;
}