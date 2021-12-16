#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_lastname 50
#define num_marks 3

#define marks_min 2
#define marks_max 5

struct element
{
    char lastname [max_lastname];
    int marks[num_marks];
    
    struct element *prev;
    struct element *next;
};

struct element *first = NULL;
struct element *last = NULL;



int main()
{
    FILE *f = fopen("extask02-a.txt", "r");
    
    while (1)
    {
        char lastname[max_lastname];
        if (fscanf(f, "%s", lastname) != 1) break;

        struct element *e = (struct element *) malloc(sizeof(struct element));
        if (last == NULL)
        {
            e -> prev = NULL;
            e-> next = NULL;
            first = e;
            last = e; 
        }
        else 
        {
            last -> next = e;
            e -> prev = last;
            e -> next = NULL;
            last = e;
        }

        strcpy(e -> lastname, lastname);
        for (int i = 0; i < num_marks; i++)
        e -> marks[i] = marks_min + rand() % (marks_max - marks_min + 1);

    }
    
    
    fclose(f);

    struct element *current = first;
    while (current != NULL)
    {
        printf("%s", current->lastname);
        for (int i = 0; i < num_marks; i++)
        printf(" %d", current->marks[i]);
        printf("\n");

        current = current -> next;
    }

    for (int i = 0; i < num_marks; i++)
    {
        if (i == marks_min)
        {
            current->marks[i] = 0;
        }
    }

    for (int i = 0; i < num_marks; i++)
    {
        if (current->marks[i] != 0)
        {
            printf("%s", current->lastname);
            for (int i = 0; i < num_marks; i++)
            printf(" %d", current->marks[i]);
            printf("\n");
        }
    }

    
    
    return 0;

}