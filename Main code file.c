#include<stdio.h>
#include<string.h>
#define MAX_TRANSACTIONS 50


int transaction_count = 0;
float transaction_income[MAX_TRANSACTIONS];
float transaction_expense[MAX_TRANSACTIONS];
char description[MAX_TRANSACTIONS][25];

float income_function()
{
    float amount;
    printf("Enter income amount: ");
    scanf("%f", &amount);
    transaction_income[transaction_count] = amount;
    printf("Enter description: ");
    scanf("%s", description[transaction_count]);
    transaction_count++;
}


float expense_function()
{
    float amount;
    int choice;
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    do
    {
    printf("What type of expense is this? (1. Daily, 2. Weekly, 3. Monthly");
    scanf("%d", &choice);
    if(choice == 1)
    {
        amount = amount * 30;
    }
    else if(choice == 2)
    {
        amount = amount * 4;
    }
    else if(choice == 3)
    {
        amount = amount;
    }
    else
    {
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
    }
    } while(choice < 1 || choice > 3);
    transaction_expense[transaction_count] = amount;
    printf("Enter description: ");
    scanf("%s", description[transaction_count]);
    transaction_count++;
}

void view_summary()
{

}

int main()
{
    int choice, run = 1;
    do
    {
        printf("=====================================\n");
        printf("Main Menu\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            income_function();
            transaction_count++;
            break;
        case 2:
            expense_function();
            transaction_count++;
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

    } while(run == 1);

    return 0;
}
