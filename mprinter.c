//#include <printf.h>
#include "mprinter.h"
#include <stdio.h>
//вывод матрицы с заданной точностью
void Print_mas(int M, float mass[][M],int N, int precision) {
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(precision==3){
                printf("%3.3f   ",mass[i][j]);
            }
            if(precision==4){
                printf("%3.4f   ",mass[i][j]);
            }
            if(precision==5){
                printf("%3.5f   ",mass[i][j]);
            }
            if(precision==6){
                printf("%3.6f   ",mass[i][j]);
            }
            if(precision==7){
                printf("%3.7f   ",mass[i][j]);
            }
            if(precision==8){
                printf("%3.8f   ",mass[i][j]);
            }

        }
        printf("\n");
    }
}
//вывод в экспоненциальном формате(для матрицы А)
void Print_exp_mas(int M, float mass[][M],int N) {
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%E   ",mass[i][j]);

        }
        printf("\n");
    }
}


// сюда решение