#include "check_errors.h"
#include "execute_modes.h"
#include "input_output.h"

int check_files_errors(int argc, char **argv)
{
    if (argc == 5)
    {
        FILE *file_first = fopen(argv[INDEX_FIRST_FILE_IN], "r");

        if (file_first == NULL)
            return ERROR_OPEN_FILE;

        FILE *file_second = fopen(argv[INDEX_SECOND_FILE_IN], "r");

        if (file_second == NULL)
        {
            fclose(file_first);
            return ERROR_OPEN_FILE;
        }

        FILE *file_third = fopen(argv[INDEX_THIRD_FILE_OUT], "w");

        if (file_third == NULL)
        {
            fclose(file_first);
            fclose(file_second);
            return ERROR_OPEN_FILE;
        }

        fclose(file_first);
        fclose(file_second);
        fclose(file_third);

        return EXIT_SUCCESS;
    }
    else if (argc == 4)
    {
        FILE *file_first = fopen(argv[INDEX_FIRST_FILE_IN], "r");

        if (file_first == NULL)
            return ERROR_OPEN_FILE;

        FILE *file_second = fopen(argv[INDEX_SECOND_FILE_OUT], "w");

        if (file_second == NULL)
        {
            fclose(file_first);
            return ERROR_OPEN_FILE;
        }

        fclose(file_first);
        fclose(file_second);

        return EXIT_SUCCESS;
    }

    return ERROR_ARGS_NUMBER;
}

int check_matrix(FILE *f_in)
{
    int temp1, temp2, flag = EXIT_SUCCESS;

    if (fscanf(f_in, "%d%d", &temp1, &temp2) != READ_SIZES)
        flag = ERROR_READ_SIZES;
    if (!flag && read_matrix_to_check(f_in, temp1, temp2))
        flag = ERROR_READ_DATA;
    if (!flag && temp1 != temp2)
        flag = ERROR_STRUCT_SIZES;

    rewind(f_in);
    return flag;
}

int read_matrix_to_check(FILE *f_in, int rows, int columns)
{
    double temp;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (fscanf(f_in, "%lf", &temp) != READ_NUMBER)
                return ERROR_READ_DATA;

    return EXIT_SUCCESS;
}

int check_matrices(FILE *f_in_1, FILE *f_in_2, int mode)
{
    int temp1, temp2, temp3, temp4, flag = EXIT_SUCCESS;

    if (fscanf(f_in_1, "%d%d", &temp1, &temp2) != READ_SIZES)
        flag = ERROR_READ_SIZES;
    if (!flag && fscanf(f_in_2, "%d%d", &temp3, &temp4) != READ_SIZES)
        flag = ERROR_READ_SIZES;
    if (!flag && read_matrix_to_check(f_in_1, temp1, temp2))
        flag = ERROR_READ_DATA;
    if (!flag && read_matrix_to_check(f_in_2, temp3, temp4))
        flag = ERROR_READ_DATA;
    if (!flag && mode == 1 && (temp1 != temp3 || temp2 != temp4))
        flag = ERROR_STRUCT_SIZES;
    if (!flag && mode == 2 && (temp2 != temp3))
        flag = ERROR_STRUCT_SIZES;

    rewind(f_in_1);
    rewind(f_in_2);
    return flag;
}
