#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Added for system() function

#define MAX_ORDERS 100

// Structure to store an order
typedef struct {
    int orderNumber;
    char dishName[100];
    int quantity;
} Order;

// Global array to store orders
Order orders[MAX_ORDERS];
int numOrders = 0;

// Function to display the restaurant schedule
void displaySchedule() {
    system("cls"); // Added to clear the screen
    printf("*************************************************************************\n");
    printf("\t\t\t    Restaurant Schedule\n");
    printf("\n");
    printf("---------------------------Monday: 8 AM - 10 PM---------------------------\n");
    printf("---------------------------Tuesday: 8 AM - 10 PM---------------------------\n");
    printf("---------------------------Wednesday: 8 AM - 10 PM---------------------------\n");
    printf("---------------------------Thursday: 8 AM - 10 PM---------------------------\n");
    printf("---------------------------Friday: 8 AM - 11 PM---------------------------\n");
    printf("---------------------------Saturday: 9 AM - 11 PM---------------------------\n");
    printf("---------------------------Sunday: 9 AM - 10 PM---------------------------\n");
    printf("\n");
    printf("*************************************************************************\n");
}

// Function to display the restaurant menu
void displayMenu() {
    system("cls"); // Added to clear the screen
    printf("*************************************************************************\n");
    printf("Description-------------------Item Name--------------------Price(tk)\n");
    printf("\n");
    printf("1.--------------------------- Burger ---------------------- 250 PKR\n");
    printf("2.--------------------------- Pizza ----------------------- 850 PKR\n");
    printf("3.--------------------------- Pasta ----------------------- 300 pKR\n");
    printf("4.--------------------------- Salad ------------------------250 PKR\n");
    printf("5.--------------------------- Sandwich ---------------------360 PKR\n");
    printf("\n");
    printf("*************************************************************************\n");
}

// Function to check if a dish name exists in the menu
int isDishAvailable(const char* dishName) {
    if (
        (strcmp(dishName, "Burger") == 0 || strcmp(dishName, "burger") == 0) ||
        (strcmp(dishName, "Pizza") == 0 || strcmp(dishName, "pizza") == 0 ) ||
        (strcmp(dishName, "Pasta") == 0 ||  strcmp(dishName, "pasta") == 0) ||
        (strcmp(dishName, "Salad") == 0 || strcmp(dishName, "salad") == 0) ||
        (strcmp(dishName, "Sandwich") == 0 || strcmp(dishName, "sandwich") == 0)) {
        return 1;
    }
    return 0;
}

// Function to place an order
void placeOrder() {
    system("cls"); // Added to clear the screen
    Order newOrder;
    printf("*************************************************************************\n");
    printf("Description------------------Available Dishes---------------------Price(tk)\n");
    printf("\n");
    printf("1.--------------------------- Burger ---------------------- 250 PKR\n");
    printf("2.--------------------------- Pizza ----------------------- 850 PKR\n");
    printf("3.--------------------------- Pasta ----------------------- 300 pKR\n");
    printf("4.--------------------------- Salad ------------------------250 PKR\n");
    printf("5.--------------------------- Sandwich ---------------------360 PKR\n");
    printf("\n");
    printf("*************************************************************************\n");
    printf("Enter dish name: ");
    scanf("%s", newOrder.dishName);

    // Check if the dish name exists in the menu
    if (!isDishAvailable(newOrder.dishName)) {
        printf("Sorry, the selected dish is unavailable.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &newOrder.quantity);

    // Calculate the total price
    float price = 0.0;
    if (strcmp(newOrder.dishName, "Burger") == 0 || strcmp(newOrder.dishName, "burger") == 0) {
        price = 250.0;
    } else if (strcmp(newOrder.dishName, "Pizza") == 0 || strcmp(newOrder.dishName, "pizza") == 0) {
        price = 850.0;
    } else if (strcmp(newOrder.dishName, "Pasta") == 0 || strcmp(newOrder.dishName, "pasta") == 0) {
        price = 300.0;
    } else if (strcmp(newOrder.dishName, "Salad") == 0 || strcmp(newOrder.dishName, "salad") == 0) {
        price = 250.0;
    } else if (strcmp(newOrder.dishName, "Sandwich") == 0 || strcmp(newOrder.dishName, "sandwich") == 0) {
        price = 360.0;
    }

    float totalPrice = price * newOrder.quantity;

    newOrder.orderNumber = numOrders + 1;

    printf("\t\t\t\t\t -----------Order Details--------------\n");
    printf("\n");
    printf("\t\t\t\t\t\t   Order Number: %d\n", newOrder.orderNumber);
    printf("\t\t\t\t\t\t   Dish Name: %s\n", newOrder.dishName);
    printf("\t\t\t\t\t\t   Quantity: %d\n", newOrder.quantity);
    printf("\t\t\t\t\t\t   Total Price: %.2f PKR\n", totalPrice);
    printf("-------------------\n");

    printf("Would you like to edit the order? (Type 'y' for yes, 'n' for no): ");
    char editChoice;
    scanf(" %c", &editChoice);

    if (editChoice == 'y' || editChoice == 'Y') {
        printf("Enter dish name: ");
        scanf("%s", newOrder.dishName);

        // Check if the dish name exists in the menu
        if (!isDishAvailable(newOrder.dishName)) {
            printf("Sorry, the selected dish is unavailable.\n");
            return;
        }

        printf("Enter quantity: ");
        scanf("%d", &newOrder.quantity);

        totalPrice = price * newOrder.quantity;

        printf("\t\t\t\t\t -----------Order placed successfully--------------.\n");

        printf("\t\t\t\t\t -----------Updated Order Details--------------\n");
        printf("\n");
        printf("\t\t\t\t\t\t   Order Number: %d\n", newOrder.orderNumber);
        printf("\t\t\t\t\t\t   Dish Name: %s\n", newOrder.dishName);
        printf("\t\t\t\t\t\t   Quantity: %d\n", newOrder.quantity);
        printf("\t\t\t\t\t\t   Total Price: %.2f PKR\n", totalPrice);
        printf("-------------------\n");
    }

    orders[numOrders] = newOrder;
    numOrders++;
}

// Function to delete an order
void deleteOrder(int orderNumber) {
    int orderIndex = -1;

    // Find the index of the order to delete
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].orderNumber == orderNumber) {
            orderIndex = i;
            break;
        }
    }

    if (orderIndex == -1) {
        printf("*******************Order not found.**************************\n");
        return;
    }

    // Shift orders to remove the deleted order
    for (int i = orderIndex; i < numOrders - 1; i++) {
        orders[i] = orders[i + 1];
    }

    numOrders--;

    printf("**************Order deleted successfully******************.\n");
}

// Function to display all orders
void displayOrders() {
    system("cls"); // Clear the screen
    printf("******************Orders*****************************\n");
    printf("------\n");
    if (numOrders == 0) {
        printf("-------------------No orders found------------------------.\n");
    } else {
        for (int i = 0; i < numOrders; i++) {
            printf("Order Number: %d\n", orders[i].orderNumber);
            printf("Dish Name: %s\n", orders[i].dishName);
            printf("Quantity: %d\n", orders[i].quantity);

            // Calculate the total price
            float price = 0.0;
            if (strcmp(orders[i].dishName, "Burger") == 0 || strcmp(orders[i].dishName, "burger") == 0) {
                price = 250.0;
            } else if (strcmp(orders[i].dishName, "Pizza") == 0 || strcmp(orders[i].dishName, "pizza") == 0) {
                price = 850.0;
            } else if (strcmp(orders[i].dishName, "Pasta") == 0 || strcmp(orders[i].dishName, "pasta") == 0) {
                price = 300.0;
            } else if (strcmp(orders[i].dishName, "Salad") == 0 || strcmp(orders[i].dishName, "salad") == 0) {
                price = 250.0;
            } else if (strcmp(orders[i].dishName, "Sandwich") == 0 || strcmp(orders[i].dishName, "sandwich") == 0) {
                price = 360.0;
            }

            float totalPrice = price * orders[i].quantity;

            printf("Total Price: %.2f PKR\n", totalPrice);
            printf("-------------------\n");
        }
    }
}


int main() {
    int choice;
    do {
        system("cls"); // Clear the screen
        printf("CRUD System\n");
        printf("-----------\n");
        printf("1. View Restaurant Schedule\n");
        printf("2. View Menu\n");
        printf("3. Place an Order\n");
        printf("4. View Orders\n");
        printf("5. Delete an Order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySchedule();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                placeOrder();
                break;
            case 4:
                displayOrders();
                break;
            case 5: {
                int orderNumber;
                printf("Enter the order number to delete: ");
                scanf("%d", &orderNumber);
                deleteOrder(orderNumber);
                break;
            }
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
        printf("Press Enter key to continue...");
        getchar(); // Clear the newline character from the input buffer
        getchar(); // Wait for the Enter key

    } while (choice != 6);

    return 0;
}
