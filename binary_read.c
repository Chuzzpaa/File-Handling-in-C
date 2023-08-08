#include <stdio.h>
#include <stdlib.h>
#include "binary_read.h"

int validate_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fclose(fp);

    return (file_size == MATRIX_SIZE * sizeof(int));
}

void print_matrix(int matrix[MATRIX_SIZE]) {
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j) 
        {
            printf("%2d ", matrix[i * 4 + j]);
        }
        printf("\n");
    }
}


int main() {
    char filename[100];
    int matrix[MATRIX_SIZE];

    printf("Enter a filename: ");
    scanf("%s", filename);

    if (validate_file(filename)) 
    {
        FILE *fp = fopen(filename, "rb"); // Open in read bianry mode
        if (fp != NULL) {
            fread(matrix, sizeof(int), MATRIX_SIZE, fp); // Read the matrix from bianry file
            fclose(fp);

            for (int i = 0; i < 4; ++i) 
            {
                for (int j = 0; j < 4; ++j) 
                {
                    printf("%3d ", matrix[i * 4 + j]);
                }
                printf("\n");
            }
        }
    } 
    else 
    {
        printf("Invalid file.\n");
    }

    return 0;
}