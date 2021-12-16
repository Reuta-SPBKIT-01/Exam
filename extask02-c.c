#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_lastname 50
#define num_marks 3
#define mark_min 2
#define mark_max 5
struct element
{
	char lastname[max_lastname];
	int marks[num_marks];

	struct element *prev;
	struct element *next;
};
struct element *first = NULL;
struct element *last = NULL;
int main()
{ 
	FILE *f = fopen("extask02list.txt", "r");
	while (1)
		{
			char lastname[max_lastname];
 			if(fscanf(f, "%s", lastname)!= 1) break;

			struct element *e = (struct element *) malloc(sizeof(struct element));
 			if (last == NULL) 

			{
				 e->prev = NULL;
				 e->next = NULL;
				 first = e;
				 last = e;
 			}
 		else
		{
 			last->next = e;
			e->prev = last;
			e->next = NULL;
			last = e;
		}
	strcpy(e->lastname, lastname);
 	for (int i = 0; i < num_marks; i++)
	e->marks[i] = mark_min + rand() % (mark_max - mark_min + 1);
} 
fclose(f);
struct element *current = first;
while (current != NULL)
{
	printf("%s", current->lastname);
	for (int i = 0; i < num_marks; i++)
	printf(" %d", current->marks[i]);
	printf("\n");
	 current = current->next;
}
printf("\n");
current = last;
while (current != NULL)
{
	printf("%s", current->lastname);
	for (int i = 0; i < num_marks; i++)
	printf(" %d", current->marks[i]);
	printf("\n");
	current = current->prev;
}
printf("\n");
current = first;
int two = 0;
while (current != NULL)
{
	for (int i = 0; i < num_marks; i++)
	if (current->marks[i] == 2)
	two++;
	if (two > 1)
	{
		current->next->prev = current->prev;
	 	current->prev->next = current->next;
		struct element * temp = current->next;
		free(current);
		current = temp;
	}
	else current = current->next;
	two = 0;
} 
current = first;
while (current != NULL)
{
	printf("%s", current->lastname);
	for (int i = 0; i < num_marks; i++)
	printf(" %d", current->marks[i]); printf("\n");
	current = current->next;
} 
printf("\n");
return 0;
}