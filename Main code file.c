#include<stdio.h>
#include<string.h>
#define MAX_TRANSACTIONS 100


int main()
{
    int transaction_count = 0;
    int transaction[MAX_TRANSACTIONS];
    char description[MAX_TRANSACTIONS][100];
    int choice, run = 1;
    do
    {
        printf("Main Menu\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            transaction[transaction_count] = income_function();
            transaction_count++;
            break;
        case 2:
            transaction[transaction_count] = expense_function();
            transaction_count++;
            break;
        case 3:
            view_summary(transaction, description, transaction_count);
            break;
        case 4:
            run = 0;
            break;
        }
    } while(run == 1);
    
    return 0;
}