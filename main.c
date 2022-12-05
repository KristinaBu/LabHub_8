#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "mprinter.h"

int factorial(int f){
    if(f==1||f==0)return 1;
    return f* factorial(f-1);

}
//генератор диапазона для размера матрицы, precision и х
int iRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
//заполнение матрицы А в соотвестсвии с заданными формулами
void mass_for_A(int M, float mass[][M],int N,int x){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==j) mass[i-1][j-1]=1;
            if(i>j) mass[i-1][j-1]=(float)pow(((float)(-x)/(float)(factorial(j))),i);
            if(i<j) mass[i-1][j-1]=(float)pow(((float)(x)/(float)(factorial(j))),i);
        }
    }
}
//заполнение матрицы В
void mass_for_B(float mass[][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mass[i][j]=(float)(i*10+j);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    rand();
    int lower = 3, upper = 8;
    int precision= iRandom(lower,upper);
    lower =1, upper = 3;
    int x= iRandom(lower,upper);

    lower = 8, upper = 10;
    //размер матрицы N на M
    //можно преобразовать из квадратной в прямоугольную
    int N=iRandom(lower, upper);
    int M=N;
    printf("Размер=%d\nprecision=%d\nx=%d\n\n",M,precision, x);
    float A[N][M];

    //Расчет матриц и вывод:

    //матрица А
    mass_for_A(M, A, N,x);
    printf("вывод матрицы А с точностью %d:\n",precision);
    Print_mas(M, A, N,precision);
    printf("\n");
    printf("вывод матрицы А в экспоненциальном формате:\n");
    Print_exp_mas(M, A, N);
    printf("\n\n");

    //матрица В
    float B[10][10];
    mass_for_B(B);
    printf("вывод матрицы B:\n");
    Print_mas(10,B,10,precision);

    //задание к матрице В
    printf("\n\n");
    printf("B=%f, B[0]=%f, B[2]=%f\n", B, B[0], B[2]);
    printf("B[0][0]=%f, **B=%f, *B[0]=%f\n", B[0][0], **B, *B[0]);
    printf("*(*(B+1))=%f, *B[1]=%f\n", *(*(B+1)), *B[1]);
    printf("*(B[0]+1)=%f, *(*B+1)=%f\n", *(B[0]+1), *(*B+1));
    printf("B[0][20]=%f, *(B[0]+20)=%f, *B[2]=%f\n", B[0][20], *(*B+1), *(B[0]+20), *B[2]);

    return 0;
}
