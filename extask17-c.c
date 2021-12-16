#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[256];
    printf("enter the string:\n");
    fgets(s, 256, stdin);
    char *p = strchr(s, '\n');
    if (p != NULL) p[0] = '\0';
    size_t n = strlen(s);
    printf("len: %ld\n", n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (n > 0 && i == 0) 
        {
            char d = toupper(s[0]);
            s[0] = d;
        }
        if (s[i] == ' ') m++;
        if (s[i] == ' ' && i < n - 1)
        {
            char d = toupper(s[i + 1]);
            s[i + 1] = d;
        }
    }
    if (n > 0) m++;
    printf("words: %d\n", m);
    for (int i = 0; i < n; i++)
        printf("%c", s[i]);
    printf("\n");
    int bb = 0;
    int c = 0;
    int i = 0;
    while (i < n)
    {
        printf("word: ");
        int j = 0;
        for (j = i; j < n; j++)
        {
            c++;
            if (s[j] != ' ') 
            {
                printf("%c", s[j]);
                bb++;
            }
            else j = n;
        }
        printf(" ");
        i += bb + 1;
        printf("len: %d\n", bb);
        bb = 0;
        if (i == n) break;
    }
    return 0;
}