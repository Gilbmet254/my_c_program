#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the number of students and subjects
#define NUM_STUDENTS 10
#define NUM_SUBJECTS 8

// Define the KCAU grading system
const char* calculate_grade(float average_score) {
    if (average_score >= 70) return "A";
    else if (average_score >= 60) return "B";
    else if (average_score >= 50) return "C";
    else if (average_score >= 40) return "D";
    else return "E";
}

const char* calculate_recommendation(float average_score) {
    if (average_score >= 70) return "Excellent";
    else if (average_score >= 60) return "Good";
    else if (average_score >= 50) return "Satisfactory";
    else if (average_score >= 40) return "Pass";
    else return "Fail";
}

// Define student structure
typedef struct {
    char name[50];
    int id;
    int scores[NUM_SUBJECTS];
} Student;

// Define updated subjects
const char* subjects[NUM_SUBJECTS] = {
    "Computer Applications", "Introduction to Programming", "Principles of DB",
    "Fundamentals of Computer Systems", "Discreet Mathematics", "Computing Mathematics",
    "Foundations of Critical and Creative Thinking", "Health Awareness and Life Skills"
};

// Function to generate random scores for each subject
void generate_scores(int scores[NUM_SUBJECTS]) {
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        scores[i] = rand() % 101; // Random score between 0 and 100
    }
}

// Function to calculate the average score
float calculate_average(int scores[NUM_SUBJECTS]) {
    int sum = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        sum += scores[i];
    }
    return (float)sum / NUM_SUBJECTS;
}

// Function to display the report card
void display_report_card(Student student, int scores[NUM_SUBJECTS], float average_score, const char* grade, const char* recommendation) {
    time_t now;
    time(&now);
    printf("\n--- Report Card ---\n");
    printf("Student Name: %s\n", student.name);
    printf("Student ID: %d\n", student.id);
    printf("\nSubject Scores:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%s: %d\n", subjects[i], scores[i]);
    }
    printf("\nAverage Score: %.2f\n", average_score);
    printf("Grade: %s\n", grade);
    printf("Recommendation: %s\n", recommendation);
    printf("Date: %s", ctime(&now));
    printf("-------------------\n");
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Define student details
    Student students[NUM_STUDENTS] = {
        {"Gilbmet", 1001}, {"Jeff", 1002}, {"Kaly", 1003}, {"Golskie", 1004}, {"Janny", 1005},
        {"Stacy", 1006}, {"Cece", 1007}, {"Rita", 1008}, {"John", 1009}, {"Fide", 1010}
    };

    // Process each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int scores[NUM_SUBJECTS];
        generate_scores(scores);
        float average_score = calculate_average(scores);
        const char* grade = calculate_grade(average_score);
        const char* recommendation = calculate_recommendation(average_score);
        display_report_card(students[i], scores, average_score, grade, recommendation);
    }

    return 0;
}
