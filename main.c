#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "mprinter.h"

// Рекурсия - враг народа!
/*
int factorial(int f){
    return f == 1 || f == 0 ? 1 : f * factorial(f-1);
}
*/
int factorial(int f) {
    f = abs(f); // а вдруг дурак захочет ввести отрицательное число?
    int r = f;
    while (f != 1 && f != 0) {
        r = r * (f - 1);
        f--;
    }
    return r;
}

//генератор диапазона для размера матрицы, precision и х
int iRandom(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

//заполнение матрицы А в соответствии с заданными формулами
void mass_for_A(int M, float mass[][M], int N, int x) {
    // ламерский путь, делаем как про! а ещё тут ошибка, главная диагональ должна быть заполнена единицами
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==j) mass[i-1][j-1]=1;
            else if(i>j) mass[i-1][j-1]=(float)pow(((float)(-x)/(float)(factorial(j))),i);
            else mass[i-1][j-1]=(float)pow(((float)(x)/(float)(factorial(j))),i);
        }
    }
    */
    // итерируем не от единицы, а от нуля до М или N не включительно!
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            mass[i][j] = i == j ? 1 : (float)pow(((float)(i > j ? -x : x)/(float)(factorial(j))), i);
        }
    }
     */
    // уже круче, но мы киберкотлетки, так что делаем такую элементарщину в одну строчку
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) mass[i][j] = i == j ? 1 : (float) pow(
                    ((float) (i > j ? -x : x) / (float) (factorial(j + 1))), i + 1);
}

//заполнение матрицы В
void mass_for_B(int mass[10][10]) {
    // ну какой ламер делает в несколько строк?
    /*
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mass[i][j]=(float)(i*10+j);
        }
    }
    */
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) mass[i][j] = (int) (i * 10 + j);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int lower = 3, upper = 8;
    int precision = iRandom(lower, upper);
    lower = 1, upper = 3;
    const int x = iRandom(lower, upper);

    lower = 8, upper = 10;
    //размер матрицы N на M
    //можно преобразовать из квадратной в прямоугольную
    const int N = iRandom(lower, upper);
    const int M = N;
    printf("Размер=%d\nprecision=%d\nx=%d\n\n", M, precision, x);
    float A[N][M];

    //Расчет матриц и вывод:

    //матрица А
    mass_for_A(M, A, N, x);
    printf("вывод матрицы А с точностью %d:\n", precision);
    print_list(M, A, N, precision);
    printf("\n");
    printf("вывод матрицы А в экспоненциальном формате:\n");
    print_exp_list(M, A, N);
    printf("\n\n");

    //матрица В
    int B[10][10];
    mass_for_B(B);
    printf("вывод матрицы B:\n");
    print_simple_list(10, B, 10);

    //задание к матрице В
    printf("\n\n");
    printf("B=%d, B[0]=%d, B[2]=%d\n", B, B[0], B[2]);
    printf("B[0][0]=%d, **B=%d, *B[0]=%d\n", B[0][0], **B, *B[0]);
    printf("*(*(B+1))=%d, *B[1]=%d\n", *(*(B + 1)), *B[1]);
    printf("*(B[0]+1)=%d, *(*B+1)=%d\n", *(B[0] + 1), *(*B + 1));
    printf("B[0][20]=%d, *(*B+1)=%d, *(B[0]+20)=%d, *B[2]=%d\n", B[0][20], *(*B + 1), *(B[0] + 20), *B[2]);

    // Примечание: так как массивы A и B были созданы статическим путём (т.е. без использования malloc), то
    // у нас нет необходимости освобождать память :)

    return 0;
}
