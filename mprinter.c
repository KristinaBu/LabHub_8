#include "mprinter.h"
#include <stdio.h>
#include "string.h"

//вывод матрицы с заданной точностью
void print_list(int M, float mass[][M], int N, int precision) {
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char buffer[10];
            sprintf(buffer, "%%15.%df", precision);
            printf(buffer, mass[i][j]);
        }
        printf("\n");
    }
}

// вывод матрицы целых чисел без заданной точности (массив B)
void print_simple_list(int M, int mass[][M], int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) printf("%02d ", mass[i][j]);
        printf("\n");
    }
}

//вывод в экспоненциальном формате(для матрицы А)
void print_exp_list(int M, float mass[][M], int N) {
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%10.2E  ", mass[i][j]);
        }
        printf("\n");
    }
}