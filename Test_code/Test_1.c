#include "Test_1.h"

int main(void) {
    double *v = NULL;
    int count = input_number_of_values();

    if (count <= 0) {
        fprintf(stderr, "The number of values must be positive.\n");
        return 1;
    }

    v = input_from_console(v, count);
    if (v == NULL) return 1;

    print(v, count);
    printf("Sum: %g\n", get_sum(v, count));
    free(v);

    return 0;
}