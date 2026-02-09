#include<stdio.h>
#include<string.h>
#define MAX_TRANSACTIONS 100

/*Global Variables and Array Declarations*/
int transaction_count = 0;
float transaction[MAX_TRANSACTIONS];
char description[MAX_TRANSACTIONS][25];

/*Function Declarations*/
/*Anan*/
float income_function()
{
    float amount;
    printf("Enter income amount: ");
    scanf("%f", &amount);
    transaction[transaction_count] = amount;
    printf("Enter description: ");
    scanf("%s", description[transaction_count]);
    transaction_count++;
}


/*Anan plus Tanvir*/
float expense_function()
{
    float amount;
    int choice;
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    do
    {
    printf("What type of expense is this? (1. Daily, 2. Weekly, 3. Monthly, 4. One time)\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        amount = amount * 30;
    }
    else if(choice == 2)
    {
        amount = amount * 4;
    }
    else if(choice == 3 || choice == 4)
    {
        amount = amount;
    }
    else
    {
        printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
    }
    } while(choice < 1 || choice > 4);
    transaction[transaction_count] = -amount;
    printf("Enter description: ");
    scanf("%s", description[transaction_count]);
    transaction_count++;
}


/*Nusrat*/
void view_summary()
{
    int i;
    float total_income = 0;
    float total_expense = 0;

    if (transaction_count == 0)
    {
        printf("Summary cannot be shown. No data found.\n");
        return;
    }
    printf("************************************\n");
    printf("Transactions\n");
    for (int i = 0; i < transaction_count; i++)
    {
        if (transaction[i] > 0)
        {
            printf("Income  : %.2f | %s\n", transaction[i], description[i]);
            total_income += transaction[i];
        }
        else
        {
            printf("Expense : %.2f | %s\n", -transaction[i], description[i]);
            total_expense += -transaction[i];
        }
    }

    printf("************************************\n");
    printf("Summary\n");
    printf("Total Income  : %.2f\n", total_income);
    printf("Total Expense : %.2f\n", total_expense * (-1));
    printf("Balance       : %.2f\n", total_income - total_expense);
}


/*Fuad*/
void warning()
{
    int i;
    float total_income = 0;
    float total_expense = 0;

    for (i = 0; i < transaction_count; i++)
    {
        if (transaction[i] > 0)
            total_income += transaction[i];
        else
            total_expense += transaction[i];
    }

    if(total_expense * -1 > total_income)
    {
        printf("\n");
        printf("\033[1;31mWARNING: You have spent more money than you have!\033[0m\n");
    }
}


/*Ratul*/
int main()
{
    int choice, run = 1;
    while(run == 1)
    {
        printf("************************************\n");
        printf("Main Menu\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            income_function();
            break;
        case 2:
            expense_function();
            break;
        case 3:
            view_summary();
            break;
        case 4:
            printf("This will clear all transactions and exit the program. Are you sure? (y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if(confirm == 'y' || confirm == 'Y')
            {
                printf("Exiting the program. Goodbye!\n");
                run = 0;
            }
            break;
        default:
            printf("Invalid choice! Please enter a number from 1 to 4.\n");
            break;
        }

        warning();
    }
    return 0;
}
