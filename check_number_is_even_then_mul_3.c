#include <stdio.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        int result = number * 3;
        printf("The result is: %d\n", result);
    }

    return 0;
}
