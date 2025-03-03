#include <stdio.h>

int main() {
    int itemCode, quantity;
    float unitPrice, subtotal, grandTotal = 0;
    char anotherItem;

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

        printf("\nSNo.\tItem Code\tUnit Price\tQuantity\tSubtotal\n");
        printf("1\t%d\t\t%.2f\t\t%d\t\t%.2f\n", itemCode, unitPrice, quantity, subtotal);

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &anotherItem);
    } while (anotherItem == 'y' || anotherItem == 'Y');

    printf("\nGrand Total: %.2f\n", grandTotal);

    return 0;
}
