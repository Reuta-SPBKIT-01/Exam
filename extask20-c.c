#include <stdio.h>
#include <string.h>
#define max_txt 256
int main()
{
    FILE *f1 = fopen("extask20-in.txt", "r");
    FILE *f2 = fopen("extask20-out.txt", "w+");
    int m = 0;
    char p[max_txt];   
    while (1)
    {
        char s[max_txt];
        if (fgets(s, max_txt, f1) == NULL) break;        
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        int l_max = strlen(s);
        if (l_max > m)
        {
            m = l_max;
            strcpy(p, s);
        }
        printf("%s %d\n", s, l_max);
    }    
    printf("str_max = %s, len = %d\n", p, m);    
    fclose(f1);
    char ast = '*';
    char per = '\n';
    FILE *f3 = fopen("extask20-in.txt", "r");
    while (1)
    {
        char s[max_txt];
        if (fgets(s, max_txt, f3) == NULL) break;
        char *c = strchr(s, '\n');
        if (c != NULL) *c = '\0';
        int l = strlen(s);
        if (l < m)
        {                
            int dif = m - l;
            fprintf(f2, "%s", s);
            while(dif > 0)
            {
                fprintf(f2, "%c", ast);
                dif--;
            }
            fprintf(f2, "%c", per);
        }
        else fprintf(f2, "%s\n", s);
    }        
    fclose(f3);
    fclose(f2);
    return 0;
}