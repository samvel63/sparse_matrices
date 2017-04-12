#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#include "matrix.h"

int main(void)
{
    elem_type z = 1.0 + 8.0 * I;
    printf("%.2f", cimag(z));
    return 0;
}