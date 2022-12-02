#include "functions.h"

#include <math.h>

#include "defines.h"

#define EPS                             1e-06
#define NUMBER_STRING                   2
#define SCANF_MARK                      1

#define ERROR_DATA_FILE                 -2
#define ERROR_DATA_FILE                 -2
#define ERROR_NO_NEED_RECORDS           -3
#define ERROR_NUMBER_MARKS              -4
#define ERROR_LONG_STRING               -5
#define ERROR_READ_STRING               -6
#define ERROR_TOO_LONG_STRING           -7

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

void bubble_sort_struct(student_t students[], const size_t number_students)
{
    for (size_t i = 0; i < number_students - 1; i++)
        for (size_t j = 0; j < number_students - i - 1; j++)
        {
            int temp_strcmp = strcmp(students[j].surname, students[j + 1].surname);

            if (temp_strcmp > 0)
                SWAP(students[j], students[j + 1], student_t);
            else if (temp_strcmp == 0 && strcmp(students[j].name, students[j + 1].name) > 0)
                SWAP(students[j], students[j + 1], student_t);
        }
}

int surname_substring(FILE *const f_src, const student_t students[], const size_t number_students, const char *const substr)
{
    int counter = 0;
    size_t len_substring = strlen(substr);

    for (size_t i = 0; i < number_students; i++)
        if (strncmp(students[i].surname, substr, len_substring) == 0)
        {
            print_info_file(f_src, students[i]);
            counter++;
        }

    return counter;
}

void print_info_file(FILE *const f_src, const student_t student)
{
    fprintf(f_src, "%s\n", student.surname);
    fprintf(f_src, "%s\n", student.name);

    for (size_t i = 0; i < NUMBER_MARKS; i++)
        fprintf(f_src, "%d ", student.marks[i]);

    fprintf(f_src, " \n");
}

int make_array(FILE *const f, student_t student[], size_t *const number_students)
{
    size_t count_students = 0;

    while (fscanf(f, "%s %s", student[count_students].surname, student[count_students].name) == NUMBER_STRING)
    {
        for (size_t i = 0; i < NUMBER_MARKS; i++)
            if (fscanf(f, "%u", &student[count_students].marks[i]) != SCANF_MARK)
                return ERROR_DATA_FILE;

        count_students++;

        if (count_students > MAX_LEN)
            return ERROR_DATA_FILE;
    }
    
    *number_students = count_students;
    return EXIT_SUCCESS;
}

void print_info(const student_t student)
{
    printf("%s\n", student.surname);
    printf("%s\n", student.name);

    for (size_t i = 0; i < NUMBER_MARKS; i++)
        printf("%d ", student.marks[i]);
        
    printf("\n");
}

double mean_arithmetic_one_student(const unsigned int array[], const size_t size)
{
    double mean_arithmetic = 0;

    for (size_t i = 0; i < size; i++)
        mean_arithmetic += array[i];

    mean_arithmetic /= NUMBER_MARKS;

    return mean_arithmetic;
}
    
double mean_arithmetic_all_students(const student_t *const students, const size_t number_students)
{
    double mean_arithmetic = 0;

    for (size_t i = 0; i < number_students; i++)
        for (size_t j = 0; j < NUMBER_MARKS; j++)
            mean_arithmetic += students[i].marks[j];

    mean_arithmetic /= number_students * NUMBER_MARKS;

    return mean_arithmetic;
}

int create_new_file(FILE *const f_dst, const student_t students[], const size_t number_students)
{
    double mean_arithmetic_all = mean_arithmetic_all_students(students, number_students);
    size_t number_reports = 0;

    for (size_t i = 0; i < number_students; i++)
    {
        double mean_arithmetic_one = mean_arithmetic_one_student(students[i].marks, NUMBER_MARKS);
    
        if (mean_arithmetic_one > mean_arithmetic_all || \
            fabs(mean_arithmetic_one - mean_arithmetic_all) < EPS)
        {
            print_info_file(f_dst, students[i]);
            number_reports++;
        }
    }

    return number_reports;
}
