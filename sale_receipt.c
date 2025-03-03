#include <stdio.h>

int main() {
    int itemCode, quantity;
    float unitPrice, subtotal, grandTotal = 0;
    char anotherItem;

    // Arrays to store item details
    int itemCodes[100];
    float unitPrices[100];
    int quantities[100];
    float subtotals[100];
    int itemCount = 0;

    do {
        printf("Enter item code: ");
        scanf("%d", &itemCode);
        printf("Enter unit price: ");
        scanf("%f", &unitPrice);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if (quantity > 4) {
            printf("Error: Cannot buy more than 4 units of the same item.\n");
            continue;
        }

        subtotal = unitPrice * quantity;
        grandTotal += subtotal;

        // Store item details in arrays
        itemCodes[itemCount] = itemCode;
        unitPrices[itemCount] = unitPrice;
        quantities[itemCount] = quantity;
        subtotals[itemCount] = subtotal;
        itemCount++;

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &anotherItem);
    } while (anotherItem == 'y' || anotherItem == 'Y');

    // Print the receipt
    printf("\n\n========== RECEIPT ==========\n");
    printf("SNo.\tItem Code\tUnit Price\tQuantity\tSubtotal\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%d\t\t%.2f\t\t%d\t\t%.2f\n", 
               i + 1, itemCodes[i], unitPrices[i], quantities[i], subtotals[i]);
    }

    printf("------------------------------------------------------------\n");
    printf("Grand Total: %.2f\n", grandTotal);
    printf("=============================\n");

    return 0;
}
