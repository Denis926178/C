#include <check.h>

#include "struct.h"
#include "sort.h"
#include "operations_list.h"
#include "matrix_actions.h"
#include "input_output.h"

START_TEST(test_multiply)
{
    int rc = 0;
    matrix_list_t *matrix_1 = NULL;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i * j != 0)
            {
                matrix_list_t *temp = element_create(i, j, i * j);
                matrix_1 = list_add(matrix_1, temp);
            }
    
    matrix_list_t *matrix_2 = NULL;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i + j != 0)
            {
                matrix_list_t *temp = element_create(i, j, i + j);
                matrix_2 = list_add(matrix_2, temp);
            }

    matrix_list_t *result = multiply(matrix_1, matrix_2);
    int flag = 0;
    int array[6] = {5, 8, 11, 10, 16, 22 };
    int i = 0;

    matrix_list_t *temp = result;

    while (temp != NULL)
    {
        if (temp->value != array[i])
            flag = 1;
        i++;
        temp = temp->next;
    }

    list_free(matrix_1);
    list_free(matrix_2);
    list_free(result);

    ck_assert_int_eq(rc, flag);
}
END_TEST

START_TEST(test_summarise)
{
    int rc = 0;
    matrix_list_t *matrix_1 = NULL;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i * j != 0)
            {
                matrix_list_t *temp = element_create(i, j, i * j);
                matrix_1 = list_add(matrix_1, temp);
            }
    
    matrix_list_t *matrix_2 = NULL;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i + j != 0)
            {
                matrix_list_t *temp = element_create(i, j, i + j);
                matrix_2 = list_add(matrix_2, temp);
            }

    summarise(matrix_1, matrix_2);
    int flag = 0;
    int array[8] = {1, 2, 1, 3, 5, 2, 5, 8};
    int i = 0;
    matrix_list_t *temp = matrix_2; 

    while (temp != NULL)
    {
        if (temp->value != array[i])
            flag = 1;
        i++;
        temp = temp->next;
    }

    list_free(matrix_1);
    list_free(matrix_2);

    ck_assert_int_eq(rc, flag);
}
END_TEST

Suite *matrix_operations_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("matrix_operations");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multiply);
    tcase_add_test(tc_pos, test_summarise);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = matrix_operations_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
