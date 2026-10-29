#include <stdio.h>
#include <string.h>

struct Customer
{
    int id;
    char name[50];
    float previousReading;
    float currentReading;
    float units;
    float bill;
};

struct Customer c;
int registered = 0;

void registerCustomer()
{
    printf("\nEnter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter Customer Name: ");
    scanf(" %s49[^\n]", c.name);

    printf("Enter Previous Meter Reading: ");
    scanf("%f", &c.previousReading);

    printf("Enter Current Meter Reading: ");
    scanf("%f", &c.currentReading);

    if (c.previousReading < 0 ||
        c.currentReading < c.previousReading)
    {
        printf("\nInvalid meter readings!\n");
        registered = 0;
        return;
    }

    c.units = c.currentReading - c.previousReading;
    registered = 1;

    printf("\nCustomer registered successfully!\n");
}


void calculateBill()
{
    float energyCharge = 0;
    float fixedCharge = 100;

    if (registered == 0)
    {
        printf("\nPlease register the customer first!\n");
        return;
    }

    
    if (c.units <= 50)
    {
        energyCharge = c.units * 3;
    }
    else if (c.units <= 100)
    {
        energyCharge = (50 * 3) +
                       ((c.units - 50) * 5);
    }
    else
    {
        energyCharge = (50 * 3) +
                       (50 * 5) +
                       ((c.units - 100) * 7);
    }

    c.bill = energyCharge + fixedCharge;

    printf("\n========== ELECTRICITY BILL ==========\n");
    printf("Customer ID       : %d\n", c.id);
    printf("Customer Name     : %s\n", c.name);
    printf("Previous Reading  : %.2f\n", c.previousReading);
    printf("Current Reading   : %.2f\n", c.currentReading);
    printf("Units Consumed    : %.2f\n", c.units);
    printf("Energy Charges    : Rs. %.2f\n", energyCharge);
    printf("Fixed Charges     : Rs. %.2f\n", fixedCharge);
    printf("--------------------------------------\n");
    printf("Total Bill        : Rs. %.2f\n", c.bill);
    printf("======================================\n");
}


void displayCustomer()
{
    if (registered == 0)
    {
        printf("\nNo customer registered!\n");
        return;
    }

    printf("\n========== CUSTOMER DETAILS ==========\n");
    printf("Customer ID      : %d\n", c.id);
    printf("Customer Name    : %s\n", c.name);
    printf("Previous Reading : %.2f\n", c.previousReading);
    printf("Current Reading  : %.2f\n", c.currentReading);
    printf("Units Consumed   : %.2f\n", c.units);
    printf("======================================\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("  ELECTRICITY BILL MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Register Customer\n");
        printf("2. Calculate Electricity Bill\n");
        printf("3. Display Customer Details\n");
        printf("4. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                registerCustomer();
                break;

            case 2:
                calculateBill();
                break;

            case 3:
                displayCustomer();
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}