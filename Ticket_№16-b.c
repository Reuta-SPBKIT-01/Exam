#include <stdio.h>
#include <stdlib.h>

struct record
{
    char drag_name[64];
    char indication[64];
    int exp_years;
    int mfg_years;
};

#define n 3
struct record row[n];

int main()
{
    //char name[] = "data.txt";
    FILE *data = fopen("data.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(data, "%s %s %d %d\n", row[i].drag_name, row[i].indication, &row[i].exp_years, &row[i].mfg_years);
    }
    fclose(data);

    printf("name\tindics\texp\tyears\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%s\t%d\t%d\n", row[i].drag_name, row[i].indication, row[i].exp_years, row[i].mfg_years);
    }

    FILE *res = fopen("results.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(res, "%s\t%s\t%d\t%d\n", row[i].drag_name, row[i].indication, row[i].exp_years, row[i].mfg_years);
    }
    fclose(res);

    return 0;
}