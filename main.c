#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include "matrix.h"

int main(void)
{
	int n, m;
	elem_type val;
	Matrix mat;
	scanf("%d %d", &n, &m);
    create(&mat, n, m);
    int x = 0;
    //double x = 0.0, y = 0.0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		scanf("%d", &x);
    		//scanf("%lf %lf", &x, &y);
    		//val = x + y * I;
    		insert(&mat, i, j, x);
    		//printf("%.2lf %.2lf", creal(val), cimag(val));
    	}
    }
    CheckOnNullRows(&mat);
    for (int i = 0; i < mat.n; ++i)
    	printf("%d\n", mat.rowp[i]);

    for (int i = 0; i < mat.entries; ++i)
    	printf("column=%d, val=%d\n", mat.column[i], mat.elem[i]);

    for (int i = 0; i <= mat.n; ++i)
    	printf("%d ", mat.rowp[i]);
    printf("\n");
    print(&mat);	
    return 0;
}