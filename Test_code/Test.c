#include "Test_1.h"

int input_number_of_values() {
    int count = 0;
    printf("Enter the number of values: ");
    fflush(stdout);
    if (scanf("%d", &count) == 1 && count > 0) return count;
    return count;
}

double *input_from_console(double *data, int count) {
    if (data == NULL && count > 0) data = calloc(count, sizeof(double));

    if (NULL == data) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter an array of %d values: ", count);
    fflush(stdout);
    for (int i = 0; i < count; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            free(data);
            return NULL;
        }
    }
    return data;
}

void print(const double *data, int count) {
    if (data == NULL || count <= 0) return;

    for (int i = 0; i < count; i++) {
        printf("%g ", data[i]);
    }
    printf("\n");
}

double get_sum(const double *data, int count) {
    double sum = 0.0;

    if (data == NULL || count <= 0) return sum;

    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum;
}

void assert_equal(double expected, double actual, const char *message) {
    if (expected == actual) {
        printf("PASS: %s\n", message);
    } else {
        printf("FAIL: %s (expected %g, actual %g)\n",
               message, expected, actual);
    }
}