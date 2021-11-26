/*
    задаётся точка где находится пушка, даются координаты выстрела,
    угол под которым вылетает снаряд и его сокрость.
    найти где приземлится снаряд, время полёта и расчитать координаты падения?
    3 - просто расчёт
    4 - вывод во время цикла
    5 - с помошью бисекций
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float x0, y0;

    printf("x0, y0: ");
    scanf("%f %f", &x0, &y0);

    float v0, alpha; 
    printf("speed, alpha: ");
    scanf("%f %f", &v0, &alpha);

    float rad = alpha * (float) M_PI / 180.0f;

    float v0x = cosf(rad) * v0;
    float v0y = sinf(rad) * v0;

#define g 9.8f
    float d =  v0y * v0y + 4.0f * g / 2.0f * y0;
    printf("d = %f\n", d);

    float t1 = (-v0y - sqrtf(d)) / (2.0f * (-g / 2.0f));
    float t2 = (-v0y + sqrtf(d)) / (2.0f * (-g / 2.0f));

    printf("t1 = %f, t2 = %f\n", t1, t2);

    float t = 0.0f;
#define eps 0.01f
    float x,y;
    while (1)
    {
        x = x0 + v0x * t;
        y = y0 + v0y * t - g * t * t / 2.0f;

        if (y <= 0.0f) break;
        t += eps; 
    }

    printf("t = %f, x = %f, y = %f\n", t, x, y);
    return 0;
}