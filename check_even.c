#include <stdio.h>

int main() {
    int number;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is even
    if (number % 2 == 0) {
        printf("The number is even: %d\n", number);
    }

    return 0;
}
