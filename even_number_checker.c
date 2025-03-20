#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (!(number % 2)) {
        printf("That number is an even number\n");
    } else {
        printf("That number is not an even number\n");
    }

    return 0;
}
