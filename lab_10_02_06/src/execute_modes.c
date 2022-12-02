#include "execute_modes.h"

int execute_multiply()
{
    matrix_list_t *matrix_1 = NULL;
    matrix_list_t *matrix_2 = NULL;

    int code_return;

    if ((code_return = read_matrix(&matrix_1)))
    {
        list_free(matrix_1);
        list_free(matrix_2);
        return code_return;
    }

    if ((code_return = read_matrix(&matrix_2)))
    {
        list_free(matrix_1);
        list_free(matrix_2);
        return code_return;
    }

    matrix_list_t *result = multiply(matrix_1, matrix_2);
    result = sort(result, comparator);
    print_list(result);

    list_free(matrix_1);
    list_free(matrix_2);
    list_free(result);

    return EXIT_SUCCESS;
}

int execute_summarize()
{
    matrix_list_t *matrix_1 = NULL;
    matrix_list_t *matrix_2 = NULL;
    int code_return;

    if ((code_return = read_matrix(&matrix_1)))
    {
        list_free(matrix_1);
        list_free(matrix_2);
        return code_return;
    }

    if ((code_return = read_matrix(&matrix_2)))
    {
        list_free(matrix_1);
        list_free(matrix_2);
        return code_return;
    }

    summarise(matrix_1, matrix_2);
    matrix_list_t *temp_head_2 = matrix_2;
    temp_head_2 = sort(temp_head_2, comparator);

    print_list(matrix_2);

    list_free(matrix_1);
    list_free(matrix_2);

    return EXIT_SUCCESS;
}

int execute_print()
{
    matrix_list_t *matrix = NULL;
    int code_return;

    if ((code_return = read_matrix(&matrix)))
    {
        list_free(matrix);
        return code_return;
    }

    print_list(matrix);

    list_free(matrix);

    return EXIT_SUCCESS;
}

int execute_delete_element()
{
    matrix_list_t *matrix = NULL;

    int code_return;

    if ((code_return = read_matrix(&matrix)))
        return code_return;

    int index_string_max_el = find_string_max_element(matrix);
    matrix_list_t *temp = matrix;

    for (temp = matrix; temp; temp = temp->next)
        temp = pop(index_string_max_el, temp);

    print_list(matrix);
    list_free(matrix);

    return EXIT_SUCCESS;
}
