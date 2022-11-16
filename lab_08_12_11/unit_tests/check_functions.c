#include <check.h>
#include <stdlib.h>

#include "math_options.h"
#include "memory_options.h"

START_TEST(test_summarize_matrices)
{
    int rc = 0;

    double **matrix_1 = allocate_matrix(2, 2);
    double **matrix_2 = allocate_matrix(2, 2);
    double **res_matrix = allocate_matrix(2, 2);
    double **known_res_matrix = allocate_matrix(2, 2);
    
    matrix_1[0][0] = 3;
    matrix_1[0][1] = 4;
    matrix_1[1][0] = 7;
    matrix_1[1][1] = 8;

    matrix_2[0][0] = 6;
    matrix_2[0][1] = 3;
    matrix_2[1][0] = 2;
    matrix_2[1][1] = 0;

    known_res_matrix[0][0] = 9;
    known_res_matrix[0][1] = 7;
    known_res_matrix[1][0] = 9;
    known_res_matrix[1][1] = 8;
    
    summarize_matrix(matrix_1, matrix_2, res_matrix, 2, 2);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (res_matrix[i][j] != known_res_matrix[i][j])
                rc = 1;

    free_matrix(matrix_1, 2);
    free_matrix(matrix_2, 2);
    free_matrix(res_matrix, 2);
    free_matrix(known_res_matrix, 2);

    ck_assert_int_eq(rc, 0);

}END_TEST

START_TEST(test_multiply_matrices)
{
    int rc = 0;

    double **matrix_1 = allocate_matrix(2, 2);
    double **matrix_2 = allocate_matrix(2, 2);
    double **res_matrix = allocate_matrix(2, 2);
    double **known_res_matrix = allocate_matrix(2, 2);
    
    matrix_1[0][0] = 3;
    matrix_1[0][1] = 4;
    matrix_1[1][0] = 7;
    matrix_1[1][1] = 8;

    matrix_2[0][0] = 6;
    matrix_2[0][1] = 3;
    matrix_2[1][0] = 2;
    matrix_2[1][1] = 0;

    known_res_matrix[0][0] = 26;
    known_res_matrix[0][1] = 9;
    known_res_matrix[1][0] = 58;
    known_res_matrix[1][1] = 21;
    
    multiply_matrix(matrix_1, matrix_2, res_matrix, 2, 2, 2);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (res_matrix[i][j] != known_res_matrix[i][j])
                rc = 1;

    free_matrix(matrix_1, 2);
    free_matrix(matrix_2, 2);
    free_matrix(res_matrix, 2);
    free_matrix(known_res_matrix, 2);

    ck_assert_int_eq(rc, 0);

}END_TEST

START_TEST(test_det)
{
    double **matrix_1 = allocate_matrix(2, 2);
    double det;

    matrix_1[0][0] = 3;
    matrix_1[0][1] = 4;
    matrix_1[1][0] = 7;
    matrix_1[1][1] = 8;
    
    det = count_determinant(matrix_1, 2);

    free_matrix(matrix_1, 2);

    ck_assert_double_eq(det, -4);

}END_TEST

Suite *math_options_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("math_options");
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_det);
    tcase_add_test(tc_pos, test_multiply_matrices);
    tcase_add_test(tc_pos, test_summarize_matrices);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = math_options_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
