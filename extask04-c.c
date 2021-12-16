#include <stdio.h>
#include <math.h>
double ff(double x)
{
    return -3.0 * cos(x);
}
int main()
{
    FILE *f = fopen("extask04-out.txt", "w+");
    double a, b;
    printf("a, b: ");
    scanf("%lf %lf", &a, &b);
    double eps;
    printf("eps: ");
    scanf("%lf", &eps);
    double c, fa, fc;
    int n = 1;
    printf("n  a\t   b\t   c\t   fa\t    fc\n");
    fprintf(f, "n  a\t   b\t   c\t   fa\t    fc\n");
    do
    {
        c = (a + b) * 0.5;
        fa = ff(a);
        fc = ff(c);
        printf("%d %.5lf %.5lf %.5lf %.5lf %.5lf\n", n, a, b, c, fa, fc);
        fprintf(f, "%d %.5lf %.5lf %.5lf %.5lf %.5lf\n", n, a, b, c, fa, fc);
        if (fa * fc < 0.0) b = c;
        else a = c;
        n++;
    }
    while (fabs(b-a) > eps);
    printf("x: %.6lf\n", c);
    printf("y: %.6lf\n", fc);
    printf("n: %d\n", n-1);
    fprintf(f, "x: %.6lf\n", c);
    fprintf(f, "y: %.6lf\n", fc);
    fprintf(f, "n: %d\n", n-1);
    fclose(f);
    return 0;
}