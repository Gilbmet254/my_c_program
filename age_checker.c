#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 20 && age <= 25) {
        printf("You are an adult\n");
    } else {
        printf("That age has not been considered\n");
    }

    return 0;
}
