#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
// Coffee types and their ingredient requirements
#define espresso "Espresso"
#define cappuccino "Cappuccino"
#define mocha "Mocha"

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

void order() {
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
        
        int choice;
        do {
            printf("Choose (1-3 or 0 to exit): ");
            scanf("%d", &choice);
        } while (choice < 0 || choice > 3);

        if (choice == 0) {
            return;
        }

        // Serve the selected coffee type
        int beansUsed = 0, waterUsed = 0, milkUsed = 0, chocolateUsed = 0;
        double price = 0;
        const char *selectedCoffee = 0;

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

        // Payment Section
        double amountPaid = 0;
        printf("The price for your %s is AED %.2f. Please insert coins (1 or 0.5 Dirham):\n", selectedCoffee, price);
        while (amountPaid < price) {
            double coin;
            printf("Insert coin: ");
            scanf("%lf", &coin);
            if (coin == 1.0 || coin == 0.5) {
                amountPaid += coin;
                printf("Total inserted: AED %.2f\n", amountPaid);
            } else {
                printf("Invalid coin! Please insert 1 or 0.5 Dirham.\n");
            }
        }

        // Calculate change
        double change = amountPaid - price ;
        if (change > 0) {
            printf("Your change: AED %.2f\n", change);
        }

        // Update ingredients and total sales
        totalBeans -= beansUsed;
        totalWater -= waterUsed;
        totalMilk -= milkUsed;
        totalChocolate -= chocolateUsed;
        totalSales += price;

        // Print coffee details
        
        printf("You paid: AED %.2f, Price: AED %.2f \n", amountPaid, price);

        // Check if ingredients are below the minimum levels
        if (totalBeans < minBeans) {
            printf("Alert: Beans are  low!\n");
        }
        if (totalWater < minWater) {
            printf("Alert: Water is  low!\n");
        }
        if (totalMilk < minMilk) {
            printf("Alert: Milk is  low!\n");
        }
        if (totalChocolate < minChocolate) {
            printf("Alert: Chocolate is  low!\n");
        }
    }
}

void admin() {
    char password[20];

    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, adminPassword) != 0) {
        printf("Incorrect password. Exiting Admin Mode.\n");
        return;
    }

    int aChoice;
    do {
        printf("\nAdmin Mode:\n");
        printf("1: Display ingredient quantities and total sales\n");
        printf("2: Replenish ingredients\n");
        printf("3: Change coffee price\n");
        printf("0: Exit Admin Mode\n");

        printf("Choose (0-3): ");
        scanf("%d", &aChoice);

        switch (aChoice) {
            case 1:
                // Display the current quantities and total sales
                printf("Current Ingredient Levels:\n");
                printf("Beans: %d\n", totalBeans);
                printf("Water: %d\n", totalWater);
                printf("Milk: %d\n", totalMilk);
                printf("Chocolate: %d\n", totalChocolate);
                printf("Total Sales: AED %.2f\n", totalSales);
                break;

            case 2:
                // Replenish ingredients to random values
                
                totalBeans =+ 150;   
                totalWater =+ 200;    // 200 - 299
                totalMilk =+ 150;     // 150 - 249
                totalChocolate =+ 50;  // 50 - 99

                printf("Ingredients have been replenished.\n");
                printf("Updated Ingredient Levels:\n");
                printf("Beans: %d\n", totalBeans);
                printf("Water: %d\n", totalWater);
                printf("Milk: %d\n", totalMilk);
                printf("Chocolate: %d\n", totalChocolate);
                break;

            case 3:
                // Change coffee prices
                {
                    int coffeeChoice;
                    double newPrice;

                    printf("Select Coffee to change price:\n");
                    printf("1. Espresso (Current Price: AED %.2f)\n", espressoPrice);
                    printf("2. Cappuccino (Current Price: AED %.2f)\n", cappuccinoPrice);
                    printf("3. Mocha (Current Price: AED %.2f)\n", mochaPrice);

                    do {
                        printf("Choose (1-3): ");
                        scanf("%d", &coffeeChoice);
                    } while (coffeeChoice < 1 || coffeeChoice > 3);

                    printf("Enter new price: AED ");
                    scanf("%lf", &newPrice);

                    switch (coffeeChoice) {
                        case 1:
                            espressoPrice = newPrice;
                            printf("New price for the Espressos: AED %.2f\n", espressoPrice);
                            break;
                        case 2:
                            cappuccinoPrice = newPrice;
                            printf("New price for the Cappuccinos: AED %.2f\n", cappuccinoPrice);
                            break;
                        case 3:
                            mochaPrice = newPrice;
                            printf("New price for the Mochas: AED %.2f\n", mochaPrice);
                            break;
                    }
                }
                break;

            case 0:
                
                break;

            default:
                printf("Invalid\n");
        }
    } while (aChoice != 0);
}


int main() {
    int choice;

    do {
        printf("1 Order \n");
        printf("2 Admin mode \n");
        printf("3 End the application \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                order();
                break;
            case 2:
                admin();
                break;
            case 3:
                printf("Exiting App.a..\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
