#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void reverse(char *data, int len);
void input_minus_long(long int *data, size_t max_len, size_t *index, char *buffer);
void input_minus(int *data, size_t max_len, size_t *index, char *buffer);
void input_minus_short(short int *data, size_t max_len, size_t *index, char *buffer);
void parse_d_i_long(long int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_d_i(int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_d_i_short(short int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_to_sys_long(unsigned long int data, char *string_data, int *i, int sys);
void parse_to_sys(unsigned int data, char *string_data, int *i, int sys);
void parse_to_sys_short(unsigned short int data, char *string_data, int *i, int sys);
void copy_to_buffer(int i, size_t *index, char *buffer, char *string_data, size_t max_len);
void parse_o_x_long(unsigned long int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_o_x(unsigned int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_o_x_short(unsigned short int data, size_t max_len, size_t *index, char *buffer, int sys);
void parse_c(char data, size_t max_len, size_t *index, char *buffer);
void parse_s(char *data, size_t max_len, size_t *index, char *buffer);
int my_snprintf(char *buffer, size_t num, char *format, ...);

#endif
