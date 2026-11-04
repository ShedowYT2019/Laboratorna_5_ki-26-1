#ifndef MYLAB_H_
#define MYLAB_H_

#include <stdio.h>
#include <stdlib.h>

// #define Use_Test

int input_number_of_values(void);
double *input_from_console(double *data, int count);
void print(const double *data, int count);
double get_sum(const double *data, int count);
void assert_equal(double expected, double actual, const char *message);

#endif // MYLAB_H_