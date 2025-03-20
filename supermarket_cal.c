#include <stdio.h>

int main() {
    float amount_spent, net_amount;
    char gender, marital_status;
    int discount = 0;

    // Input from the user
    printf("Enter the amount spent (Kshs): ");
    scanf("%f", &amount_spent);

    printf("Are you married? (Y/N): ");
    scanf(" %c", &marital_status); // Note the space before %c to consume any leftover newline character

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    // Determine discount based on conditions
    if (amount_spent >= 0 && amount_spent <= 2000 && marital_status == 'N' && gender == 'M') {
        discount = 5; // 5% discount for unmarried males spending 0-2000
    } else if (amount_spent >= 2001 && amount_spent <= 4500 && marital_status == 'Y' && gender == 'F') {
        discount = 10; // 10% discount for married females spending 2001-4500
    } else if (amount_spent >= 4600 && amount_spent <= 10000 && marital_status == 'Y' && gender == 'F') {
        discount = 15; // 15% discount for married females spending 4600-10000
    } else if (amount_spent > 10000) {
        discount = 20; // 20% discount for anyone spending over 10000
    }

    // Calculate net amount
    net_amount = amount_spent - (amount_spent * discount / 100);

    // Output the result
    printf("Net amount payable: Kshs %.2f\n", net_amount);

    return 0;
}
