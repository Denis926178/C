#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"

int make_array(FILE *const f, student_t student[], size_t *const number_students);                                                  // для всех задач
void bubble_sort_struct(student_t students[], const size_t number_students);                                                          // для 1 задачи
void print_info(const student_t student);                                                                                           // для 1 задачи
int surname_substring(FILE *const f_src, const student_t students[], const size_t number_students, const char *const substring);    // для 2 задачи
void print_info_file(FILE *const f_src, const student_t student);                                                                   // для 2-3 задачи
double mean_arithmetic_one_student(const unsigned int array[], const size_t size);                                                  // для 3 задачи
double mean_arithmetic_all_students(const student_t *const students, const size_t number_students);                                 // для 3 задачи
int create_new_file(FILE *const f_dst, const student_t students[], const size_t number_students);                                 // для 3 задачи

#endif
