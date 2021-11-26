#include <stdio.h>
#include <stdlib.h> //для rand
#define days 31
int pressure[days];

#define p_min 740
#define p_max 780
#define p_norm 760

int main()
{
    for (int i = 0; i < days; i++)
    {
        pressure[i] = p_min + rand() % (p_max - p_min + 1);
    }


    printf("day\tpressure\n");
    for (int i = 0; i < days; i++)
    {
        printf("%d\t%d\n", i + 1, pressure[i]);
    }

    int cnt_reduced = 0;		// пониженное
    int cnt_normal = 0;			// нормальное
    int cnt_increased = 0;		// повышенное
    for (int i = 0; i < days; i++)
    {
        int v = pressure[i];
        if (v < p_norm)
        {
        	cnt_reduced++;
        }	
        else if (v > p_norm)
        {
        	cnt_increased++;
        }	
        else cnt_normal++;
    }

    printf("reduced: %d\n", cnt_reduced);
    printf("increased: %d\n", cnt_increased);
    printf("normal: %d\n", cnt_normal);

   int selected;
    printf("witch day r u want to delete?\t");
    scanf("%d\n", &selected);
    printf("%d\n",selected);
    selected -= 1;

    for (int i = 0; i < days; i++)
    {
    	printf("%d\t%d\n", i + 1, pressure[i]);
        if(i == selected - 1)
        pressure[selected] = 0;
        
    }
  
    return 0;
}