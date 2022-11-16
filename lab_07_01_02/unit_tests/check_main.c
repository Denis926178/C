#include <check.h>
#include <stdlib.h>

#include "filter.h"
#include "sort_array.h"

START_TEST(test_filter)
{
    int rc;
    int array[] = {5, 4, -3, 2, 1};
    int *new_array_start = NULL;
    int *new_array_end = NULL;

    rc = key(array, array + 5, &new_array_start, &new_array_end);
    int flag = 0;
    for (int *i = new_array_start, counter = 0; i < new_array_end; i++, counter++)
        if (*i != array[counter])
            flag = 1;

    free(new_array_start);
    ck_assert_int_eq(rc + flag, 0);

}END_TEST

START_TEST(test_mysort)
{
    int array[] = {5, 4, -3, 2, 1};
    int sort_array[] = {-3, 1, 2, 4, 5};

    mysort(array, 5, 4, compare_int);

    int flag = 0;
    for (int *i = array, counter = 0; i < array + 5; i++, counter++)
        if (*i != sort_array[counter])
            flag = 1;

    ck_assert_int_eq(flag, 0);

}END_TEST

Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("filter");
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_filter);
    tcase_add_test(tc_pos, test_mysort);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = filter_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
