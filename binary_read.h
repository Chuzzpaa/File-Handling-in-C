#ifndef BINARY_READ_H
#define BINARY_READ_H

#include <stdio.h>

#define MATRIX_SIZE 16

int validate_file(const char *filename);
void print_matrix(int matrix[MATRIX_SIZE]);

#endif