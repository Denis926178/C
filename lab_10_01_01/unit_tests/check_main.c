#include <check.h>

#include "create_list.h"
#include "execute_modes.h"
#include "input_output.h"
#include "sort.h"
#include "struct.h"

START_TEST(test_delete_duplicates)
{
    int rc = 0;
    node_t *array_list = NULL;
    int array_start[9] = {1, 2, 1, 5, 3, 8, 1, 5, 5};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            node_t *temp = node_create((array_start + i * j + j));
            array_list = list_add(array_list, temp);
        }

    array_list = sort(array_list, comparator);
    remove_duplicates(&array_list, comparator);
    int array[5] = {1, 2, 3, 5, 8};
    int i = 0;
    int flag = 0;

    node_t *temp = array_list;

    while (temp != NULL)
    {
        if (*(int *)temp->data != array[i])
            flag = 1;
        i++;
        temp = temp->next;
    }

    list_free(array_list);
    ck_assert_int_eq(rc, flag);
}
END_TEST

START_TEST(test_sort)
{
    int rc = 0;
    node_t *array_list = NULL;
    int array_start[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        node_t *temp = node_create(&(array_start[i]));
        array_list = list_add(array_list, temp);
    }

    array_list = sort(array_list, comparator);
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int flag = 0;

    node_t *temp = array_list;

    while (temp != NULL)
    {
        if (*(int *)temp->data != array[i])
            flag = 1;
        i++;
        temp = temp->next;
    }

    list_free(array_list);
    ck_assert_int_eq(rc, flag);
}
END_TEST

Suite *array_operations_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("array_operations");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_delete_duplicates);
    tcase_add_test(tc_pos, test_sort);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = array_operations_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
