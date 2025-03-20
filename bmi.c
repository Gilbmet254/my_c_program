#include <stdio.h>

int main() {
    float weight, height, bmi;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("Weight Status: Underweight\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Weight Status: Healthy Weight\n");
    } else if (bmi >= 25.0 && bmi <= 29.9) {
        printf("Weight Status: Overweight\n");
    } else {
        printf("Weight Status: Obesity\n");
    }

    return 0;
}
