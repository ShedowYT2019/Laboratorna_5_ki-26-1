#include "mylib.h"

#include <stdio.h>
#include <stdlib.h>

double get_min_from_vector(const double *data, int count) {
    double min = data[0];

    for (int i = 1; i < count; i++) {
        if (data[i] < min) min = data[i];
    }
    return min;
}

double get_min_from_matrix(const double **data, int rows, int cols) {
    double min = data[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] < min) min = data[i][j];
        }
    }
    return min;
}

double get_max_from_vector(const double *data, int count) {
    double max = data[0];

    for (int i = 1; i < count; i++) {
        if (data[i] > max) max = data[i];
    }
    return max;
}

double get_max_from_matrix(const double **data, int rows, int cols) {
    double max = data[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] > max) max = data[i][j];
        }
    }
    return max;
}

double get_avg_from_vector(const double *data, int count) {
    double sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum / count;
}

double get_avg_from_matrix(const double **data, int rows, int cols) {
    double sum = 0.0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += data[i][j];
        }
    }
    return sum / (rows * cols);
}

void get_stat_from_vector(const double *data, int count,
                          double *min, double *max, double *avg) {
    *min = get_min_from_vector(data, count);
    *max = get_max_from_vector(data, count);
    *avg = get_avg_from_vector(data, count);
}

void get_stat_from_matrix(const double **data, int rows, int cols,
                          double *min, double *max, double *avg) {
    *min = get_min_from_matrix(data, rows, cols);
    *max = get_max_from_matrix(data, rows, cols);
    *avg = get_avg_from_matrix(data, rows, cols);
}

double *input_vector_from_console(double *data, int count) {
    if (data == NULL) data = calloc((size_t)count, sizeof(double));
    if (data == NULL) return NULL;

    for (int i = 0; i < count; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            free(data);
            return NULL;
        }
    }
    return data;
}

double **input_matrix_from_console(double **data, int rows, int cols) {
    if (data == NULL) data = calloc((size_t)rows, sizeof(double *));
    if (data == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        data[i] = calloc((size_t)cols, sizeof(double));
        if (data[i] == NULL) {
            for (int k = 0; k < i; k++) free(data[k]);
            free(data);
            return NULL;
        }

        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &data[i][j]) != 1) {
                for (int k = 0; k <= i; k++) free(data[k]);
                free(data);
                return NULL;
            }
        }
    }
    return data;
}

void print_vector(const double *data, int count) {
    for (int i = 0; i < count; i++) {
        printf("%g ", data[i]);
    }
    printf("\n");
}

void print_matrix(const double **data, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%g ", data[i][j]);
        }
        printf("\n");
    }
}
