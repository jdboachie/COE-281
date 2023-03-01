#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int order, size, time, flavour, topping;
    float cost;

    // Declare string variables for all the flavours
    char flavours[6][10];
    strcpy(flavours[1], "Vanilla");
    strcpy(flavours[2], "Strawberry");
    strcpy(flavours[3], "Chocolate");
    strcpy(flavours[4], "Mango");
    strcpy(flavours[5], "Enquiries");

    char flavour_costs[6][10];
    strcpy(flavour_costs[1], "5.00");
    strcpy(flavour_costs[2], "5.00");
    strcpy(flavour_costs[3], "6.00");
    strcpy(flavour_costs[4], "7.00");
    strcpy(flavour_costs[5], "0.00");

    // Declare string variables for all the toppings
    char toppings[5][20];
    strcpy(toppings[1], "Sprinkles");
    strcpy(toppings[2], "Whipped cream");
    strcpy(toppings[3], "Chopped Nuts");
    strcpy(toppings[4], "Coconut Shavings");

    char topping_costs[5][10];
    strcpy(topping_costs[1], "2.00");
    strcpy(topping_costs[2], "3.00");
    strcpy(topping_costs[3], "4.00");
    strcpy(topping_costs[4], "5.00");

    
    order, time, flavour, topping, size = 0;
    cost = 0.0;

    printf("WELCOME TO THE ICE CREAM SHOP\n");

    do {
        printf("What would you like to order?\n");

        // Get the flavour for the order
        printf("1. Vanilla\n2. Strawberry\n3. Chocolate\n4. Mango\n5. Enquiries\n");
        scanf("%d", &order);

        // Check if the order is for enquiries or is invalid
        if (order == 5) {
            printf("Please call 123-456-7890 for enquiries\n");
            continue;
        }
        else if (order != 1 && order != 2 && order != 3 && order != 4) {
            printf("Invalid flavour\n");
            continue;
        }

        // Get the topping for the order
        printf("1. Sprinkles\n2. Whipped cream\n3. Chopped Nuts\n4. Coconut Shavings\n");
        scanf("%d", &topping);

        // Get the size of the order
        printf("1-small\n2-medium\n3-large\n");
        scanf("%d", &size);
        
        // Print the order
        if (order == 1 || order == 2 || order == 3 || order == 4) {
            if (size == 1) {
                printf("You have ordered a small ");
            } else if (size == 2) {
                printf("You have ordered a medium ");
            } else if (size == 3) {
                printf("You have ordered a large ");
            } else {
                printf("Invalid size\n");
                continue;
            }
        }

        // Print the flavour
        for (int i = 1; i <= 5; i++)
        {
            if (i == order)
            {
                printf("%s ice cream with", flavours[i]);
                break;
            }
        }

        // Print the topping
        for (int i = 0; i <= 4; i++)
        {
            if (i == topping)
            {
                printf(" %s topping.\n", toppings[i]);
                break;
            }
        }

        // Calculate the cost
        for (int i = 0; i <= 5; i++)
        {
            if (i == order)
            {
                cost = atof(flavour_costs[i]);
                break;
            }
            
            if (i == topping)
            {
                cost += atof(topping_costs[i]);
                break;
            }
        }

        if (size == 1)
        {
            cost += 0.00;
        }
        else if (size == 2)
        {
            cost += 3.00;
        }
        else if (size == 3)
        {
            cost += 5.00;
        }

        // Print the cost and time of the order
        printf("The cost of your order is $%.2f\n", cost);
        if (size == 1)
        {
            printf("Your order will be ready in 2 minutes\n");
        }
        else if (size == 2)
        {
            printf("Your order will be ready in 3 minutes\n");
        }
        else if (size == 3)
        {
            printf("Your order will be ready in 4 minutes\n");
        }
        
        // Ask if the user wants to order again
        printf("Would you like to order again?\n1. Yes\n2. No\n");
        scanf("%d", &order);
    } while (order == 1);

    return (0);
}