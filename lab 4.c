#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Coffee types and their ingredient requirements
#define espresso = "Espresso";
#define cappuccino = "Cappuccino";
#define mocha = "Mocha";

// Ingredients for each coffee type
int espressoBeans = 8, espressoWater = 30, espressoMilk = 0, espressoChocolate = 0;
int cappuccinoBeans = 8, cappuccinoWater = 30, cappuccinoMilk = 70, cappuccinoChocolate = 0;
int mochaBeans = 8, mochaWater = 39, mochaMilk = 160, mochaChocolate = 30;

// Prices for each coffee type
double espressoPrice = 3.5;
double cappuccinoPrice = 4.5;
double mochaPrice = 5.5;

// Minimum levels for ingredients
const int minBeans = 10;
const int minWater = 50;
const int minMilk = 50;
const int minChocolate = 10;

// Current levels for ingredients
int totalBeans = 250;
int totalWater = 250;
int totalMilk = 250;
int totalChocolate = 100;

double totalSales = 0;

// Admin password
const char *adminPassword = "hello";

void orderCoffee() {
    while (1) {
        printf("Available Coffee Types:\n");

        // Check availability of each coffee type and print the menu
        if (totalBeans >= espressoBeans && totalWater >= espressoWater)
            printf("1. %s - AED %.2f\n", espresso, espressoPrice);
        else
            printf("1. %s - not available\n", espresso);

        if (totalBeans >= cappuccinoBeans && totalWater >= cappuccinoWater && totalMilk >= cappuccinoMilk)
            printf("2. %s - AED %.2f\n", cappuccino, cappuccinoPrice);
        else
            printf("2. %s - not available\n", cappuccino);

        if (totalBeans >= mochaBeans && totalWater >= mochaWater && totalMilk >= mochaMilk && totalChocolate >= mochaChocolate)
            printf("3. %s - AED %.2f\n", mocha, mochaPrice);
        else
            printf("3. %s - not available\n", mocha);
        
        // Check if any coffee is available
        if (totalBeans < espressoBeans && totalBeans < cappuccinoBeans && totalBeans < mochaBeans) {
            printf("Out of coffee. Exiting...\n");
            return;
        }
        
        int choice;
        do {
            printf("Enter your selection (1-3 or 0 to exit): ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 3);

        if (choice == 0) {
            return;
        }

        // Serve the selected coffee type
        int beansUsed = 0, waterUsed = 0, milkUsed = 0, chocolateUsed = 0;
        double price = 0;
        const char *selectedCoffee = NULL;

        switch (choice) {
            case 1:
                beansUsed = espressoBeans; waterUsed = espressoWater; milkUsed = espressoMilk; chocolateUsed = espressoChocolate;
                price = espressoPrice; selectedCoffee = espresso;
                break;
            case 2:
                beansUsed = cappuccinoBeans; waterUsed = cappuccinoWater; milkUsed = cappuccinoMilk; chocolateUsed = cappuccinoChocolate;
                price = cappuccinoPrice; selectedCoffee = cappuccino;
                break;
            case 3:
                beansUsed = mochaBeans; waterUsed = mochaWater; milkUsed = mochaMilk; chocolateUsed = mochaChocolate;
                price = mochaPrice; selectedCoffee = mocha;
                break;
        }
        
        printf("Serving your %s. Enjoy!\n", selectedCoffee);
        totalBeans -= beansUsed;
        totalWater -= waterUsed;
        totalMilk -= milkUsed;
        totalChocolate -= chocolateUsed;
        totalSales += price;
    }
}

void adminMode() {
    // Admin functionality can be implemented here
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
                orderCoffee();
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
