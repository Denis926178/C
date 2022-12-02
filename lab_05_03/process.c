#include "process.h"

#include <time.h>
#include <math.h>

#define ERROR_READ                  -1
#define ERROR_WRITE                 -2
#define ERROR_INVALID_NUMBER        -5
#define ERROR_FSEEK                 -6
#define ERROR_FTELL                 -7

#define NUMBER_READ_WRITE           1

int get_number_by_pos(FILE *const f, size_t pos, int *const number)
{
    pos *= sizeof(int);
    int code_return = fseek(f, pos, SEEK_SET);

    if (code_return)
        return code_return;
    
    if (fread(number, sizeof(int), NUMBER_READ_WRITE, f) != NUMBER_READ_WRITE)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *const f, size_t pos, int number)
{
    pos *= sizeof(int);
    int code_return = fseek(f, pos, SEEK_SET);

    if (code_return)
        return code_return;

    if (fwrite(&number, sizeof(int), NUMBER_READ_WRITE, f) != NUMBER_READ_WRITE)
        return EXIT_FAILURE;
        
    return EXIT_SUCCESS;
}

int size_file(FILE *const f, size_t *const size)
{
    if (fseek(f, 0L, SEEK_END) == EOF)
        return ERROR_FSEEK;

    *size = ftell(f);
    
    if ((int) *size == -1L)
        return ERROR_FTELL;

    if (*size < sizeof(int))
        return ERROR_READ;

    return fseek(f, 0L, SEEK_SET);
}

int input_numbers(FILE *const f, char *const count_numbers)
{
    const size_t count = atoi(count_numbers);

    srand(time(NULL));

    if (count == 0)
        return ERROR_INVALID_NUMBER;

    for (size_t i = 0; i < count; i++)
    {
        int temp = rand() % 100;

        if (fwrite(&temp, sizeof(int), NUMBER_READ_WRITE, f) != NUMBER_READ_WRITE)
            return ERROR_WRITE;
    }

    return EXIT_SUCCESS;
}

int print_numbers(FILE *const f)
{   
    size_t size;
    int code_return = size_file(f, &size);

    if (code_return)
        return code_return;

    size_t count_number = size / sizeof(int);

    for (size_t i = 0; i < count_number; i++)
    {
        int temp_number;

        if (fread(&temp_number, sizeof(int), NUMBER_READ_WRITE, f) == NUMBER_READ_WRITE)
            printf("%d ", temp_number);
        else
            return ERROR_READ;
    }

    return EXIT_SUCCESS;
}

int sort_bubble_numbers(FILE *const f)
{   
    size_t size;
    int code_return = size_file(f, &size);

    if (code_return)
        return code_return;

    const int number_elements = size / sizeof(int);

    for (int i = 0; i < number_elements - 1; i++)
        for (int j = 0; j < number_elements - i - 1; j++)
        {
            int first_number, second_number;
            if ((code_return = get_number_by_pos(f, j, &first_number)) || (code_return = get_number_by_pos(f, j + 1, &second_number)))
                return code_return;

            if (first_number > second_number)
                if ((code_return = put_number_by_pos(f, j + 1, first_number)) || (code_return = put_number_by_pos(f, j, second_number)))
                    return code_return;
        }

    return EXIT_SUCCESS;
}
