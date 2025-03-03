#include <stdio.h>

int main() {
    float amount, rate, kshs;
    char currency[10];

    printf("Enter the currency: ");
    scanf("%s", currency);
    printf("Enter the amount: ");
    scanf("%f", &amount);
    printf("Enter the exchange rate (1 %s to Kshs): ", currency);
    scanf("%f", &rate);

    kshs = amount * rate;
    printf("%.2f %s = %.2f Kshs\n", amount, currency, kshs);

    return 0;
}
