#include "execute_modes.h"
#include "math_options.h"
#include "memory_options.h"
#include "input_output.h"
#include "check_errors.h"

void select_mode(int argc, char **argv, int *mode)
{
    if (argc == 5 && !strcmp(argv[1], "a"))
        *mode = SUMMARIZE;
    else if (argc == 5 && !strcmp(argv[1], "m"))
        *mode = MULTIPLY;
    else if (argc == 4 && !strcmp(argv[1], "o"))
        *mode = DETERMINANT;
    else
        *mode = ERROR_MODE;
}

int execute_summarize(char **argv)
{
    FILE *file_first_matrix = fopen(argv[INDEX_FIRST_FILE_IN], "r");
    FILE *file_second_matrix = fopen(argv[INDEX_SECOND_FILE_IN], "r");
    FILE *file_output = fopen(argv[INDEX_THIRD_FILE_OUT], "w");

    int rows_first_matrix, rows_second_matrix;
    int columns_first_matrix, columns_second_matrix;
    int code_return, flag = EXIT_SUCCESS;
    
    if ((code_return = check_matrices(file_first_matrix, file_second_matrix, 1)))
        flag = code_return;
    
    double **first_matrix = NULL, **second_matrix = NULL, **res_matrix = NULL;

    if (!flag)
    {
        fscanf(file_first_matrix, "%d%d", &rows_first_matrix, &columns_first_matrix);
        fscanf(file_second_matrix, "%d%d", &rows_second_matrix, &columns_second_matrix);
        first_matrix = allocate_matrix(rows_first_matrix, columns_first_matrix);
        second_matrix = allocate_matrix(rows_second_matrix, columns_second_matrix);
        res_matrix = allocate_matrix(rows_first_matrix, columns_second_matrix);
        if (first_matrix == NULL || second_matrix == NULL || res_matrix == NULL)
            flag = ERROR_ALLOCATE_MEMORY;
    }

    if (!flag)
    {
        read_matrix(file_first_matrix, rows_first_matrix, columns_first_matrix, first_matrix);
        read_matrix(file_second_matrix, rows_second_matrix, columns_second_matrix, second_matrix);
        summarize_matrix(first_matrix, second_matrix, res_matrix, rows_first_matrix, columns_first_matrix);
        print_matrix(file_output, res_matrix, rows_first_matrix, columns_first_matrix);
    }

    fclose(file_first_matrix);
    fclose(file_second_matrix);
    fclose(file_output);

    if (first_matrix != NULL)
        free_matrix(first_matrix, rows_first_matrix);
    if (second_matrix != NULL)
        free_matrix(second_matrix, rows_second_matrix);
    if (res_matrix != NULL)
        free_matrix(res_matrix, rows_first_matrix);

    return flag;
}

int execute_mupltiply(char **argv)
{
    FILE *file_first_matrix = fopen(argv[INDEX_FIRST_FILE_IN], "r");
    FILE *file_second_matrix = fopen(argv[INDEX_SECOND_FILE_IN], "r");
    FILE *file_output = fopen(argv[INDEX_THIRD_FILE_OUT], "w");

    int rows_first_matrix, rows_second_matrix;
    int columns_first_matrix, columns_second_matrix;
    int code_return, flag = EXIT_SUCCESS;

    if ((code_return = check_matrices(file_first_matrix, file_second_matrix, 2)))
        flag = code_return;

    double **first_matrix = NULL, **second_matrix = NULL, **res_matrix = NULL;

    if (!flag)
    {
        fscanf(file_first_matrix, "%d%d", &rows_first_matrix, &columns_first_matrix);
        fscanf(file_second_matrix, "%d%d", &rows_second_matrix, &columns_second_matrix);
        first_matrix = allocate_matrix(rows_first_matrix, columns_first_matrix);
        second_matrix = allocate_matrix(rows_second_matrix, columns_second_matrix);
        res_matrix = allocate_matrix(rows_first_matrix, columns_second_matrix);

        if (first_matrix == NULL || second_matrix == NULL || res_matrix == NULL)
            flag = ERROR_ALLOCATE_MEMORY;
    }

    if (!flag)
    {
        read_matrix(file_first_matrix, rows_first_matrix, columns_first_matrix, first_matrix);
        read_matrix(file_second_matrix, rows_second_matrix, columns_second_matrix, second_matrix);
        multiply_matrix(first_matrix, second_matrix, res_matrix, rows_first_matrix, rows_second_matrix, columns_second_matrix);
        print_matrix(file_output, res_matrix, rows_first_matrix, columns_second_matrix);
    }

    fclose(file_first_matrix);
    fclose(file_second_matrix);
    fclose(file_output);

    if (first_matrix != NULL)
        free_matrix(first_matrix, rows_first_matrix);
    if (second_matrix != NULL)
        free_matrix(second_matrix, rows_second_matrix);
    if (res_matrix != NULL)
        free_matrix(res_matrix, rows_first_matrix);

    return flag;
}

int execute_determinant(char **argv)
{
    FILE *file_first_matrix = fopen(argv[INDEX_FIRST_FILE_IN], "r");
    FILE *file_output = fopen(argv[INDEX_SECOND_FILE_OUT], "w");

    int rows_first_matrix, columns_first_matrix, flag = EXIT_SUCCESS, code_return;

    if ((code_return = check_matrix(file_first_matrix)))
        flag = code_return;

    double **first_matrix = NULL;

    if (!flag)
        fscanf(file_first_matrix, "%d%d", &rows_first_matrix, &columns_first_matrix);

    if (!flag && (first_matrix = allocate_matrix(rows_first_matrix, columns_first_matrix)) == NULL)
        flag = ERROR_ALLOCATE_MEMORY;

    if (!flag)
        read_matrix(file_first_matrix, rows_first_matrix, columns_first_matrix, first_matrix);
        
    if (!flag)
    {
        double determinant = count_determinant(first_matrix, rows_first_matrix);
        fprintf(file_output, "%lf", determinant);
    }

    fclose(file_first_matrix);
    fclose(file_output);

    if (first_matrix != NULL)
        free_matrix(first_matrix, rows_first_matrix);

    return flag;
}
