#include <stdio.h>
#include <string.h>

int main() {
    char inputName[50];
    char correctName[] = "Gilbmet"; // Change to the correct name

    printf("Enter your name: ");
    fgets(inputName, sizeof(inputName), stdin);

    // Remove the newline character at the end of the input
    inputName[strcspn(inputName, "\n")] = '\0';

    // Compare the input name with the correct name
    if (strcmp(inputName, correctName) == 0) {
        printf("Your name is correctly spelt.\n");
    } else {
        printf("Your name is incorrectly spelt.\n");
    }

    return 0;
}
