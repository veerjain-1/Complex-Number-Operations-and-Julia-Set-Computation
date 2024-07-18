#include "complex.h"
#include <math.h>
#include <stdlib.h>

/* Add Complex Numbers */
complex_t add_complex(complex_t arg1, complex_t arg2) {
    complex_t result = {0, 0};
    result.x = arg1.x + arg2.x;
    result.y = arg1.y + arg2.y;
    return result;
}

/* Make Complex Numbers Negative */
complex_t neg_complex(complex_t arg) {
    complex_t result = {0, 0};
    result.x = -arg.x;
    result.y = -arg.y;
    return result;
}

/* Subtract Complex Numbers */
complex_t sub_complex(complex_t arg1, complex_t arg2) {
    complex_t result = {0, 0};
    result.x = arg1.x - arg2.x;
    result.y = arg1.y - arg2.y;
    return result;
}

/* Do Dot Product on Complex Numbers */
double dot_complex(complex_t arg1, complex_t arg2) {
    return arg1.x * arg2.x + arg1.y * arg2.y;
}

/* Make Complex Numbers Inverse */
complex_t inv_complex(complex_t arg) {
    complex_t result = {0, 0};
    double denom = arg.x * arg.x + arg.y * arg.y;
    result.x = arg.x / denom;
    result.y = -arg.y / denom;
    return result;
}

/* Multiply Complex Numbers */
complex_t mul_complex(complex_t arg1, complex_t arg2) {
    complex_t result = {0, 0};
    result.x = arg1.x * arg2.x - arg1.y * arg2.y;
    result.y = arg1.x * arg2.y + arg1.y * arg2.x;
    return result;
}

/* Divide Complex Numbers */
complex_t div_complex(complex_t arg1, complex_t arg2) {
    complex_t result = mul_complex(arg1, inv_complex(arg2));
    return result;
}

/* Exponent on Complex Numbers */
complex_t exp_complex(complex_t arg) {
    complex_t result = {0, 0};
    result.x = exp(arg.x) * cos(arg.y);
    result.y = exp(arg.x) * sin(arg.y);
    return result;
}

/* Compute Julia Set */
int julia(complex_t arg_z, complex_t arg_c) {
    int n = 0;
    while ((dot_complex(arg_z, arg_z) < 4.0) && (n < MAX_JULIA)) {
        n++;
        arg_z = add_complex(mul_complex(arg_z, arg_z), arg_c);
    }
    return n;
}
