/*
    3 Написать программу, выполняющую основные операции с дробями, работу пользователя организовать через меню,
    выполнить ввод и вывод дробей и из сложение и вычитание, каждое действие с дробями выполнить с помощью функций
    4 умножение и деление дробей
    5 выполнить сокращение дроби с помощью поиска наибольшего общего делителя
*/

#include <stdio.h>

int a1, b1;
int a2, b2;

void input1()
{
    printf("[1] a|b: ");
    scanf("%d %d", &a1, &b1);
}

void input2()
{
    printf("[2] a|b: ");
    scanf("%d %d", &a2, &b2);
}

void print()
{
    printf("[1]: %d / %d\n", a1, b1);
    printf("[2]: %d / %d\n", a2, b2);
}

void add()
{
    int a3 = a1 * b2 + a2 * b1;
    int b3 = b1 * b2;
    printf("[4] %d / %d\n", a3, b3);
}

void substract()
{
    int a3 = a1 * b2 - a2 * b1;
    int b3 = b1 * b2;
    printf("[5] %d / %d\n", a3, b3);
}
int main()
{
    int choice;
    do
    {
        printf("-----------------------\n");
        printf("0 - exit\n");
        printf("1 - input 1\n");
        printf("2 - input 2\n");
        printf("3 - print\n");
        printf("4 - add\n");
        printf("5 - substract\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: input1(); break;
            case 2: input2(); break;
            case 3: print(); break;
            case 4: add(); break;
            case 5: substract(); break;
        }
    }
    while (choice != 0);    
    
    return 0;
}