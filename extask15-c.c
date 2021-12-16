#include <stdio.h>
#include <string.h>
struct record
{
    char os[32];
    int virt, phy, price;
};
#define rows 3
struct record tab[rows];
int main()
{
    char tmp[32];
    for (int i = 0; i < rows; i++)
    {
        printf("[record %d]\nos, virt, phy, price: ", i);
        scanf("%s %d %d %d", tab[i].os, &tab[i].virt, &tab[i].phy, &tab[i].price);
        printf("\n");
    }
    for (int i = 0; i < rows; i++)
        printf("%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
    char os[32];
    printf("search: ");
    scanf("%s", os);
    printf("\n");
    int n = 0;
    for (int i = 0; i < rows; i++)
    {
        if (strcmp(tab[i].os, os) == 0)
        {
            printf("virt: %d\n", tab[i].virt);
            printf("phy: %d\n", tab[i].phy);
            printf("price: %d\n", tab[i].price);
            n++;
        }
    }
    if (n < 1) printf("not found\n");
    int choise = 0;
    do
    {
        printf("input minimal cost: ");
        printf("\n");
        scanf("%d", &choise);
    }
    while (choise < 0);
    n = 0;
    for (int i = 0; i < rows; i++)
    {
        if (choise > tab[i].price) 
        {
            printf("%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
            n++;
        }
    }
    if (n < 1) printf("not found\n");
    FILE *f = fopen("extask15-out.txt", "w+");
    for (int i = 0; i < rows; i++)
        fprintf(f, "%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
    fclose(f);
    return 0;
}