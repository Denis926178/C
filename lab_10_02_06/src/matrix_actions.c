#include "matrix_actions.h"

matrix_list_t *multiply(matrix_list_t *matrix_1, matrix_list_t *matrix_2)
{   
    matrix_list_t *temp_head_1 = matrix_1;
    matrix_list_t *result = NULL;
    matrix_list_t *temp_result = NULL;

    while (temp_head_1 != NULL)
    {
        matrix_list_t *temp_head_2 = matrix_2;

        while (temp_head_2 != NULL)
        {
            if (temp_head_1->col == temp_head_2->row)
            {
                temp_result = result;
                int flag = 0;

                while (temp_result != NULL)
                {
                    if (temp_result->col == temp_head_2->col && temp_result->row == temp_head_1->row)
                    {
                        temp_result->value += temp_head_1->value * temp_head_2->value;
                        flag = 1;
                    }
                    temp_result = temp_result->next;
                }

                if (!flag)
                {
                    matrix_list_t *temp_el = element_create(temp_head_1->row, temp_head_2->col, temp_head_1->value * temp_head_2->value);
                    result = list_add(result, temp_el);
                }
            }
            temp_head_2 = temp_head_2->next;
        }

        temp_head_1 = temp_head_1->next;
    }

    return result;
}

matrix_list_t *summarise(matrix_list_t *matrix_1, matrix_list_t *matrix_2)
{
    matrix_list_t *temp_head_1 = matrix_1;
    matrix_list_t *temp_head_2 = matrix_2;

    int flag = 0;

    while (temp_head_1 != NULL)
    {
        temp_head_2 = matrix_2;

        while (temp_head_2 != NULL)
        {
            if (temp_head_1->row == temp_head_2->row && temp_head_1->col == temp_head_2->col)
            {
                temp_head_2->value += temp_head_1->value;
                flag = 1;
                break;
            }

            temp_head_2 = temp_head_2->next;
        }

        if (!flag)
        {
            matrix_list_t *temp_el = element_create(temp_head_1->row, temp_head_1->col, temp_head_1->value);
            matrix_2 = list_add(matrix_2, temp_el);
        }

        flag = 0;
        temp_head_1 = temp_head_1->next;
    }

    return temp_head_2;
}
