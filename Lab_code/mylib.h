#ifndef MYLIB_H
#define MYLIB_H

#include <stddef.h>

double get_min_from_vector(const double *data, int count);
double get_min_from_matrix(const double **data, int rows, int cols);

double get_max_from_vector(const double *data, int count);
double get_max_from_matrix(const double **data, int rows, int cols);

double get_avg_from_vector(const double *data, int count);
double get_avg_from_matrix(const double **data, int rows, int cols);

void get_stat_from_vector(const double *data, int count,
                          double *min, double *max, double *avg);
void get_stat_from_matrix(const double **data, int rows, int cols,
                          double *min, double *max, double *avg);

double *input_vector_from_console(double *data, int count);
double **input_matrix_from_console(double **data, int rows, int cols);

void print_vector(const double *data, int count);
void print_matrix(const double **data, int rows, int cols);

#endif
