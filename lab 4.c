/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Coffee types and their ingredient requirements
#define coffee1 = "Espresso";
#define coffee2 = "Cappuccino";
#define coffee3 = "Mocha";

// Ingredients for each coffee type
int coffee1Beans = 8, coffee1Water = 30, coffee1Milk = 0, coffee1Chocolate = 0;
int coffee2Beans = 8, coffee2Water = 30, coffee2Milk = 70, coffee2Chocolate = 0;
int coffee3Beans = 8, coffee3Water = 39, coffee3Milk = 160, coffee3Chocolate = 30;

// Prices for each coffee type
double coffee1Price = 3.5;
double coffee2Price = 4.5;
double coffee3Price = 5.5;

// Minimum levels for ingredients
const int minCoffeeBeans = 10;
const int minWater = 50;
const int minMilk = 50;
const int minChocolateSyrup = 10;

// Current levels for ingredients
int coffeeBeans = 250;
int water = 250;
int milk = 250;
int chocolateSyrup = 100;

double totalSalesAmount = 0;

// Admin password
const char *adminPass = "hello";

void orderCoffee() {
    while (1) {
        printf("Available Coffee Types:\n");

        // Check availability of each coffee type and print the menu
        if (coffeeBeans >= coffee1Beans && water >= coffee1Water)
            printf("1. %s - AED %.2f\n", coffee1, coffee1Price);
        else
            printf("1. %s - not available\n", coffee1);

        if (coffeeBeans >= coffee2Beans && water >= coffee2Water && milk >= coffee2Milk)
            printf("2. %s - AED %.2f\n", coffee2, coffee2Price);
        else
            printf("2. %s - not avaialable\n", coffee2);

        if (coffeeBeans >= coffee3Beans && water >= coffee3Water && milk >= coffee3Milk && chocolateSyrup >= coffee3Chocolate)
            printf("3. %s - AED %.2f\n", coffee3, coffee3Price);
        else
            printf("3. %s - not available\n", coffee3);
         // Check if any coffee is available
        if (coffeeBeans < coffee1Beans && coffeeBeans < coffee2Beans && coffeeBeans < coffee3Beans) {
            printf("out of coffee. Exiting...\n");
            return;
        int choice;
        do {
            printf("Enter your selection (1-3 or 0 to exit): ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 3);

        if (choice == 0) {
            return;
        }        // Serve the selected coffee type
        int beans = 0, water = 0, milk = 0, chocolate = 0;
        double price = 0;
        const char *selectedCoffee = NULL;

        switch (choice) {
            case 1:
                beans = coffee1Beans; water = coffee1Water; milk = coffee1Milk; chocolate = coffee1Chocolate;
                price = coffee1Price; selectedCoffee = coffee1;
                break;
            case 2:
                beans = coffee2Beans; water = coffee2Water; milk = coffee2Milk; chocolate = coffee2Chocolate;
                price = coffee2Price; selectedCoffee = coffee2;
                break;

    
    }
}
void adminMode() {

}

int main() {
    int option;

    do {
        printf("        SELECT AN OPTION        \n");
        printf("1. Order a coffee type \n");
        printf("2. Admin mode for the coffee maker option \n");
        printf("3. End the application \n");
        printf("Enter the option you want to select \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                orderCof, fee();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting App...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}

