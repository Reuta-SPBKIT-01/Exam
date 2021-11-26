/*
    3 Имеются n оценок в аттестате в диапазоне от 2 до 5, вычислить средний балл поступит ли ученик с таким ср. б. в университет ели средний балл 4.6
    4 оформить отдельной функцией вычисление среднего балла
    5 использовать динамический массив
*/

#include <stdio.h>
#include <stdlib.h>

#define mmin 2
#define mmax 5
#define n_max 100
#define mpass 4.6f

int n;
int mark[n_max];



float calc_avg (int n, int mark[n_max])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += mark[i];
    return (float) sum / (float) n;    
}

int main()
{
    printf("n: ");
    scanf("%d", &n);

    printf("mark: ");
    for (int i = 0; i < n; i++)
       scanf("%d", &mark[i]);
    printf("\n");

//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    sum += mark[i];

//    float avg = (float) sum / (float) n;

//    printf("avg: %0.1f\n", avg);
    calc_avg(n, mark[n_max]);
//    if (avg < mpass)
//    printf("no");
//    else
//    printf("yes");
return 0;
}