#include <stdio.h>

int main() {
    // Declare variables
    int num_computers;
    float price_per_computer, total_sales, bonus, commission, gross_salary;
    const float base_salary = 1500.00;
    const float bonus_per_computer = 200.00;
    const float commission_rate = 0.02;

    // Input: Number of computers sold and price per computer
    printf("Enter the number of computers sold: ");
    scanf("%d", &num_computers);
    printf("Enter the price per computer: ");
    scanf("%f", &price_per_computer);

    // Calculate total sales
    total_sales = num_computers * price_per_computer;

    // Calculate bonus
    bonus = num_computers * bonus_per_computer;

    // Calculate commission
    commission = commission_rate * total_sales;

    // Calculate gross salary
    gross_salary = base_salary + bonus + commission;

    // Output the gross salary
    printf("Gross Salary: $%.2f\n", gross_salary);

    return 0;
}
