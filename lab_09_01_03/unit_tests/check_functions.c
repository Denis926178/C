#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "read.h"
#include "print.h"
#include "free.h"

START_TEST(test_read_number_records)
{
    int rc = 0;
    int count_products;
    FILE *f_src = fopen("func_tests/data/file.txt", "r");

    rc = read_number_records(&count_products, f_src);

    fclose(f_src);

    ck_assert_int_eq(rc, 0);

}END_TEST

START_TEST(test_read_file)
{
    int rc = 0;
    FILE *f_src = fopen("func_tests/data/file.txt", "r");
    product_t *products = calloc(5, sizeof(product_t));
    int temp;

    fscanf(f_src, "%d\n", &temp);
    rc = read_file(products, temp, f_src);
    free_struct(products, temp);
    
    ck_assert_int_eq(rc, 0);

}END_TEST

Suite *read_file_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("read_file");
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_read_number_records);
    tcase_add_test(tc_pos, test_read_file);

    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = read_file_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
