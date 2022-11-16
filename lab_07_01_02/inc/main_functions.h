#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#define INDEX_IN_FILE           1  
#define INDEX_OUT_FILE          2  
#define INDEX_OPTION            3  
#define MODE_FILTER_SORT        1   
#define MODE_SORT               2  

#define ERROR_ARGS_NUMBER       1  
#define ERROR_OPEN_FILE         2   
#define ERROR_CLOSE_FILE        3   
#define ERROR_NO_DATA_IN_FILE   4   
#define ERROR_MEMORY            5   
#define ERROR_ARGS_OPTION       7   

void close_files(FILE *f_in, FILE *f_out);
void select_mode(int argc, char **argv, int *mode);
int execute_mode_filter_sort(FILE *f_out, int **array, int counter);
void execute_mode_sort(FILE *f_out, int **array, int counter, int (*compar)(const void*, const void*));
int check_files_errors(int argc, char **argv, FILE **f_in, FILE **f_out);
int count_numbers(FILE *f_in, int *counter);
int init_array(int **array, FILE *f_in, int counter);

#endif
