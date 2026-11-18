#include "mylib.h" /// Імпортування заголовочного файлу mylib.h, який містить оголошення функцій та констант, що використовуються в цьому файлі.

#include <math.h> /// Імпортування стандартної бібліотеки математичних функцій для використання функції fabs.
#include <stdio.h> /// Імпортування стандартної бібліотеки вводу/виводу для використання функцій, таких як printf та scanf.
#include <stdlib.h> /// Імпортування стандартної бібліотеки динамічного виділення пам'яті для використання функцій, таких як calloc та free.

static void free_matrix(double **data, int rows) { /// Функція для звільнення пам'яті, виділеної для матриці. Приймає вказівник на масив даних та кількість рядків у ньому.
    if (data == NULL) return;

    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);
}

#ifdef USE_TEST  /// Умова компіляції для включення тестів, якщо макрос USE_TEST визначено.
static int almost_equal(double actual, double expected) {
    return fabs(actual - expected) < 0.000001;
}

static void run_tests(void) { /// Функція для запуску тестів. Використовується для перевірки правильності роботи функцій бібліотеки.
    double vector[] = {-2.0, 4.0, 6.0};
    double *vector_ptr = vector;
    double matrix_row_1[] = {1.0, 8.0};
    double matrix_row_2[] = {-3.0, 5.0};
    double *matrix[] = {matrix_row_1, matrix_row_2};
    double **matrix_ptr = matrix;
    double min, max, avg;

    printf("\nTESTS\n");
    printf("Vector min: %s\n", almost_equal(get_min_from_vector(vector_ptr, 3), -2.0) ? "PASS" : "FAIL");
    printf("Vector max: %s\n",almost_equal(get_max_from_vector(vector_ptr, 3), 6.0) ? "PASS" : "FAIL");
    printf("Vector avg: %s\n",almost_equal(get_avg_from_vector(vector_ptr, 3), 8.0 / 3.0) ? "PASS" : "FAIL");

    get_stat_from_vector(vector_ptr, 3, &min, &max, &avg);
    printf("Vector statistics: %s\n",almost_equal(min, -2.0) && almost_equal(max, 6.0) &&almost_equal(avg, 8.0 / 3.0) ? "PASS" : "FAIL");

    printf("Matrix min: %s\n",almost_equal(get_min_from_matrix((const double **)matrix_ptr, 2, 2),-3.0) ? "PASS" : "FAIL");
    printf("Matrix max: %s\n",almost_equal(get_max_from_matrix((const double **)matrix_ptr, 2, 2),8.0) ? "PASS" : "FAIL");
    printf("Matrix avg: %s\n",almost_equal(get_avg_from_matrix((const double **)matrix_ptr, 2, 2),11.0 / 4.0) ? "PASS" : "FAIL");

    get_stat_from_matrix((const double **)matrix_ptr, 2, 2,&min, &max, &avg);
    printf("Matrix statistics: %s\n",almost_equal(min, -3.0) && almost_equal(max, 8.0) &&almost_equal(avg, 11.0 / 4.0) ? "PASS" : "FAIL");
}
#endif

int main(void) { /// Головна функція програми. Виконує введення вектора та матриці з консолі, обчислює статистичні характеристики та виводить результати на консоль.
    double *v = NULL;
    double **m = NULL;
    int vector_count;
    int rows;
    int cols;
    double min, max, avg;

#ifdef USE_TEST /// Умова компіляції для запуску тестів, якщо макрос USE_TEST визначено.
    run_tests();
    return 0;
#endif /// Умова компіляції для запуску тестів, якщо макрос USE_TEST визначено.

    printf("Enter vector size: ");
    if (scanf("%d", &vector_count) != 1 || vector_count <= 0) return 1;

    printf("Enter %d vector values: ", vector_count);
    v = input_vector_from_console(v, vector_count);
    if (v == NULL) {
        fprintf(stderr, "Could not read the vector.\n");
        return 1;
    }

    printf("Enter matrix rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        free(v);
        return 1;
    }

    printf("Enter %d matrix values: ", rows * cols);
    m = input_matrix_from_console(m, rows, cols);
    if (m == NULL) {
        free(v);
        fprintf(stderr, "Could not read the matrix.\n");
        return 1;
    }

    printf("\nVector: ");
    print_vector(v, vector_count);
    get_stat_from_vector(v, vector_count, &min, &max, &avg);
    printf("Vector: min=%g, max=%g, avg=%g\n", min, max, avg);

    printf("\nMatrix:\n");
    print_matrix((const double **)m, rows, cols);
    get_stat_from_matrix((const double **)m, rows, cols, &min, &max, &avg);
    printf("Matrix: min=%g, max=%g, avg=%g\n", min, max, avg);

    free(v);
    free_matrix(m, rows);
    return 0;
}
