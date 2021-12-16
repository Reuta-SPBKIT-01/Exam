#include <stdio.h> // EXIT_SUCCESS, NULL, malloc(), free()
#include <stdlib.h> // FILE, fopen(), fclose(), fscanf()
#include <string.h> // strcpy(), strcmp()
#define max_word 64
struct element
{
    char word[max_word];
    int count;
    struct element *next;
};
struct element *first = NULL;
struct element *find(char word[max_word])
{
    struct element *current = first;
    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0) return current;
        current = current->next;
    }
    return NULL;
}
struct element *add()
{
    struct element *mem = (struct element *) malloc(sizeof(struct element));
    mem->next = first;
    first = mem;
    return mem;
}
int main()
{
    FILE *f = fopen("extask01-a-in.txt", "r");
    if (f == NULL) puts("failed to open file.");
    else
    {    
        while (1)
        {
            char temp[max_word];
            int n = fscanf(f, "%s", temp);
            if (n != 1) break;

            struct element *found = find(temp);
            if (found != NULL) found->count++;
            else
            {
                struct element *added = add();
                strcpy(added->word, temp);
                added->count = 1;
            }
        }       
        struct element *current = first;
        int min = 1;
        int max = 1;
        FILE *ff = fopen("extask01-c-out.txt", "w+");
        while (current != NULL)
        {
            fprintf(ff, "%s %d\n", current->word, current->count);
            struct element *next = current->next;
            if (current->count < min) min = current->count;
            if (current->count > max) max = current->count;
            current = next;
        }
        current = first;
        fprintf(ff, "\nmost rare word: \n");
        while (current != NULL)
        {
            struct element *next = current->next;
            if (current->count == min)
                fprintf(ff, "%s, his count = %d\n", current->word, current->count);
            current = next;
        }
        current = first;
        fprintf(ff, "\nmost common word: \n");
        while (current != NULL)
        {
            struct element *next = current->next;
            if (current->count == max)
                fprintf(ff, "%s, his count = %d\n", current->word, current->count);
            free(current);
            current = next;
        }
        fclose(ff);
    }
    fclose(f);
    return 0;
}