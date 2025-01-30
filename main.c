#include <stdio.h>
#include <stdlib.h>

void calculateExamStatistics();
void saveResultsToFile(int count, int above50, int below50, float average, int totalScores, int gradeDistribution[]);
void displayGradeDistribution(int gradeDistribution[]);

int main(void) {
    char choice;

    do {
        printf("\n--- Exam Score Analyzer ---\n");
        calculateExamStatistics();
        
        printf("\nWould you like to analyze another set of scores? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the exam score analyzer!\n");
    return 0;
}

void calculateExamStatistics() {
    int score, count = 0, sum = 0, above50 = 0, below50 = 0;
    int gradeDistribution[5] = {0}; // A, B, C, D, F
    float average;

    printf("Enter exam scores (-1 to exit): ");
    
    do {
        scanf("%d", &score);
        if (score >= 0 && score <= 100) {
            sum += score;
            count++;
            if (score >= 50) {
                above50++;
            } else {
                below50++;
            }
            
            // Grade categorization
            if (score >= 90) {
                gradeDistribution[0]++; // A
            } else if (score >= 80) {
                gradeDistribution[1]++; // B
            } else if (score >= 70) {
                gradeDistribution[2]++; // C
            } else if (score >= 60) {
                gradeDistribution[3]++; // D
            } else {
                gradeDistribution[4]++; // F
            }
        } else if (score != -1) {
            printf("Invalid exam score! Please enter a number between 0 and 100.\n");
        }
    } while (score != -1);
    
    if (count > 0) {
        average = (float)sum / count;
        printf("The average exam score is: %.2f\n", average);
        printf("Number of students with exam score >= 50: %d\n", above50);
        printf("Number of students with exam score < 50: %d\n", below50);
        
        displayGradeDistribution(gradeDistribution);
        saveResultsToFile(count, above50, below50, average, count, gradeDistribution);
    } else {
        printf("No valid scores entered.\n");
    }
}

void displayGradeDistribution(int gradeDistribution[]) {
    printf("\nGrade Distribution:\n");
    printf("A (90-100): %d\n", gradeDistribution[0]);
    printf("B (80-89): %d\n", gradeDistribution[1]);
    printf("C (70-79): %d\n", gradeDistribution[2]);
    printf("D (60-69): %d\n", gradeDistribution[3]);
    printf("F (<60): %d\n", gradeDistribution[4]);
}

void saveResultsToFile(int count, int above50, int below50, float average, int totalScores, int gradeDistribution[]) {
    FILE *file = fopen("exam_results.txt", "w");
    if (!file) {
        printf("Error creating results file!\n");
        return;
    }
    
    fprintf(file, "Exam Score Analysis:\n");
    fprintf(file, "Total number of scores entered: %d\n", totalScores);
    fprintf(file, "Average score: %.2f\n", average);
    fprintf(file, "Number of students with score >= 50: %d\n", above50);
    fprintf(file, "Number of students with score < 50: %d\n", below50);
    
    fprintf(file, "\nGrade Distribution:\n");
    fprintf(file, "A (90-100): %d\n", gradeDistribution[0]);
    fprintf(file, "B (80-89): %d\n", gradeDistribution[1]);
    fprintf(file, "C (70-79): %d\n", gradeDistribution[2]);
    fprintf(file, "D (60-69): %d\n", gradeDistribution[3]);
    fprintf(file, "F (<60): %d\n", gradeDistribution[4]);
    
    fclose(file);
    printf("Results saved to 'exam_results.txt'.\n");
}
