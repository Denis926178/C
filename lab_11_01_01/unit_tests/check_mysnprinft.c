#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_snprintf.h"

START_TEST(test_my_snprintf_d)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%d", d);
    int b = snprintf(buffer_snprintf, 50, "%d", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_i)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%i", d);
    int b = snprintf(buffer_snprintf, 50, "%i", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_x)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%x", d);
    int b = snprintf(buffer_snprintf, 50, "%x", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_o)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%o", d);
    int b = snprintf(buffer_snprintf, 50, "%o", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_c)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    char c = 'a';
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%c", c);
    int b = snprintf(buffer_snprintf, 50, "%c", c);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_s)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    char *s = "asdfb";
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%s", s);
    int b = snprintf(buffer_snprintf, 50, "%s", s);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_hd)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    short int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%hd", d);
    int b = snprintf(buffer_snprintf, 50, "%hd", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_hi)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    short int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%hi", d);
    int b = snprintf(buffer_snprintf, 50, "%hi", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_hx)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    short int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%hx", d);
    int b = snprintf(buffer_snprintf, 50, "%hx", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_ho)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    short int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%ho", d);
    int b = snprintf(buffer_snprintf, 50, "%ho", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_ld)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    long int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%ld", d);
    int b = snprintf(buffer_snprintf, 50, "%ld", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_li)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    long int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%li", d);
    int b = snprintf(buffer_snprintf, 50, "%li", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_lx)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    long int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%lx", d);
    int b = snprintf(buffer_snprintf, 50, "%lx", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(test_my_snprintf_lo)
{
    char buffer_snprintf[50];
    char buffer_my_snprintf[50];
    
    long int d = 56;
    
    int a = my_snprintf(buffer_my_snprintf, 50, "%lo", d);
    int b = snprintf(buffer_snprintf, 50, "%lo", d);
    
    int flag = 0;
    
    if (a != b || strcmp(buffer_my_snprintf, buffer_snprintf))
    	flag = 1;
    
    ck_assert_int_eq(0, flag);
}
END_TEST

Suite *my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("my_snprintf");
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_my_snprintf_d);
    tcase_add_test(tc_pos, test_my_snprintf_i);
    tcase_add_test(tc_pos, test_my_snprintf_x);
    tcase_add_test(tc_pos, test_my_snprintf_o);
    tcase_add_test(tc_pos, test_my_snprintf_c);
    tcase_add_test(tc_pos, test_my_snprintf_s);
    tcase_add_test(tc_pos, test_my_snprintf_hd);
    tcase_add_test(tc_pos, test_my_snprintf_hi);
    tcase_add_test(tc_pos, test_my_snprintf_hx);
    tcase_add_test(tc_pos, test_my_snprintf_ho);
    tcase_add_test(tc_pos, test_my_snprintf_ld);
    tcase_add_test(tc_pos, test_my_snprintf_li);
    tcase_add_test(tc_pos, test_my_snprintf_lx);
    tcase_add_test(tc_pos, test_my_snprintf_lo);
    
    suite_add_tcase(s, tc_pos);
        
    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    
    s = my_snprintf_suite();
    runner = srunner_create(s);
    
    srunner_run_all(runner, CK_VERBOSE);
    
    no_failed = srunner_ntests_failed(runner);
    
    srunner_free(runner);
    
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

