#include "functions.h"
#include "defines.h"

#define ERROR_OPEN_FILE             -1
#define ERROR_DATA_FILE             -2
#define ERROR_CLOSE_FILE            -8
#define ERROR_SPECIAL_CODE          53
#define ERROR_ARGS_NUMBER           -9
#define ERROR_NO_NEED_RECORDS       -3

#define MAX_LEN                     100
#define NUMBER_ARGS_ST              3
#define NUMBER_ARGS_FT              5
#define NUMBER_ARGS_DT              3
#define INDEX_FILE_SRC              2
#define INDEX_FILE_DST              3
#define INDEX_SUBSTR                4
#define INDEX_OPTION                1
#define EXECUTE_ST                  1
#define EXECUTE_FT                  2
#define EXECUTE_DT                  3

int close_two_file(FILE *const f_src, FILE *const f_dst)
{
    if (fclose(f_src) == EOF)
    {
        if (fclose(f_dst) == EOF)
            return ERROR_CLOSE_FILE;

        return ERROR_CLOSE_FILE;
    }
    else if (fclose(f_dst) == EOF)
    {
        return ERROR_CLOSE_FILE;
    }

    return EXIT_SUCCESS;
}

int select_mode(int const argc, char **argv, int *const mode)
{   
    if (argc != 3 && argc != 5)
        return ERROR_ARGS_NUMBER;
    
    if (argc == NUMBER_ARGS_ST && strcmp(argv[INDEX_OPTION], "st") == 0)
        *mode = EXECUTE_ST;
    else if (argc == NUMBER_ARGS_FT && strcmp(argv[INDEX_OPTION], "ft") == 0)
        *mode = EXECUTE_FT;
    else if (argc == NUMBER_ARGS_DT && strcmp(argv[INDEX_OPTION], "dt") == 0)
        *mode = EXECUTE_DT;
    else
        return ERROR_SPECIAL_CODE;

    return EXIT_SUCCESS;
}

int execute_st(char **argv, student_t students[], size_t number_student)
{
    FILE *const f_src = fopen(argv[INDEX_FILE_SRC], "r");

    if (f_src == NULL)
        return ERROR_OPEN_FILE;

    if (make_array(f_src, students, &number_student) || number_student == 0)
    {
        if (fclose(f_src) == EOF)
            return ERROR_CLOSE_FILE;

        return ERROR_DATA_FILE;
    }

    bubble_sort_struct(students, number_student);

    for (size_t i = 0; i < number_student; i++)
        print_info(students[i]);

    if (fclose(f_src) == EOF)
        return ERROR_CLOSE_FILE;
    
    return EXIT_SUCCESS;
}

int execute_ft(char **argv, student_t students[], size_t number_student)
{
    FILE *const f_src = fopen(argv[INDEX_FILE_SRC], "r");

    if (f_src == NULL)
        return ERROR_OPEN_FILE;

    FILE *const f_dst = fopen(argv[INDEX_FILE_DST], "w");

    if (f_dst == NULL)
    {
        if (fclose(f_src) == EOF)
            return ERROR_CLOSE_FILE;
            
        return ERROR_OPEN_FILE;
    }
         
    if (make_array(f_src, students, &number_student) || number_student == 0)
    {
        if (close_two_file(f_src, f_dst))
            return ERROR_CLOSE_FILE;

        return ERROR_DATA_FILE;
    }
        
    int code_return = surname_substring(f_dst, students, number_student, argv[INDEX_SUBSTR]);

    if (close_two_file(f_src, f_dst))
        return ERROR_CLOSE_FILE;

    if (!code_return)
        return ERROR_NO_NEED_RECORDS;

    return EXIT_SUCCESS;
}

int execute_dt(char **argv, student_t students[], size_t number_students)
{
    FILE *f_src = fopen(argv[INDEX_FILE_SRC], "r");
         
    if (f_src == NULL)
        return ERROR_OPEN_FILE;
        
    if (make_array(f_src, students, &number_students) || number_students == 0)
    {
        if (fclose(f_src) == EOF)
            return ERROR_CLOSE_FILE;

        return ERROR_DATA_FILE;
    }
        
    if (fclose(f_src) == EOF)
        return ERROR_CLOSE_FILE;

    f_src = fopen(argv[INDEX_FILE_SRC], "w");

    if (f_src == NULL)
        return ERROR_OPEN_FILE;

    size_t counter = create_new_file(f_src, students, number_students);

    if (counter == 0)
        return EXIT_FAILURE;

    if (fclose(f_src) == EOF)
        return ERROR_CLOSE_FILE;
    
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int mode = 0;
    int code_return = select_mode(argc, argv, &mode);
    student_t students[MAX_LEN] = { 0 };
    size_t number_student = 0;

    switch (mode)
    {
        case EXECUTE_ST:
            code_return = execute_st(argv, students, number_student);
            break;
        case EXECUTE_FT:
            code_return = execute_ft(argv, students, number_student);
            break;
        case EXECUTE_DT:
            code_return = execute_dt(argv, students, number_student);
            break;
    }

    return code_return;
}
