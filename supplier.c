#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier supplierList[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nError: System is full. Cannot add more suppliers.\n");
        return;
    }

    printf("\n--- Add New Supplier ---\n");
    int newID;
    int duplicate = 0;

    // 1. Get and validate Supplier ID
    printf("Enter Supplier ID (positive number): ");
    scanf("%d", &newID);

    if (newID <= 0) {
        printf("Error: ID must be a positive number.\n");
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < supplierCount; i++) {
        if (supplierList[i].supplierID == newID) {
            duplicate = 1;
            break;
        }
    }
    if (duplicate) {
        printf("Error: A supplier with this ID already exists.\n");
        return;
    }

    supplierList[supplierCount].supplierID = newID;

    // 2. Get and validate Name
    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", supplierList[supplierCount].name);
    if (strlen(supplierList[supplierCount].name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return;
    }
 
    printf("Enter Email: ");
    scanf(" %[^\n]", supplierList[supplierCount].email);

    printf("Enter Telephone: ");
    scanf(" %[^\n]", supplierList[supplierCount].telephone);

    printf("Enter Town/Location: ");
    scanf(" %[^\n]", supplierList[supplierCount].town);

    supplierCount++;
    printf("Success: Supplier added successfully!\n");
}

void displaySuppliers() {
    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n--- Registered Suppliers ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d:\n", i + 1);
        printf("ID: %d\n", supplierList[i].supplierID);
        printf("Name: %s\n", supplierList[i].name);
        printf("Email: %s\n", supplierList[i].email);
        printf("Telephone: %s\n", supplierList[i].telephone);
        printf("Town: %s\n", supplierList[i].town);
        printf("-----------------------------\n");
    }
}

void searchSupplier() {
    if (supplierCount == 0) {
        printf("\nNo suppliers registered to search.\n");
        return;
    }

    int searchID;
    int found = 0;

    printf("\n--- Search Supplier ---\n");
    printf("Enter Supplier ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < supplierCount; i++) {
        if (supplierList[i].supplierID == searchID) {
            printf("\nSupplier Found!\n");
            printf("ID: %d\n", supplierList[i].supplierID);
            printf("Name: %s\n", supplierList[i].name);
            printf("Email: %s\n", supplierList[i].email);
            printf("Telephone: %s\n", supplierList[i].telephone);
            printf("Town: %s\n", supplierList[i].town);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Supplier with ID %d not found.\n", searchID);
    }
}
