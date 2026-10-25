#include <stdio.h>

struct Student {
    int rollNumber;
    char name[50];
    int marks[3];
    int totalMarks;
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

   
    for (int i = 0; i < n; i++) {
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name); 

        printf("Enter marks in 3 subjects: ");
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].marks[j]);
            sum += students[i].marks[j];
        }

        students[i].totalMarks = sum;
        students[i].percentage = (sum / 300.0f) * 100;
    }

 
    for (int i = 0; i < n; i++) {
        printf("\nStudent Result:\n");
        printf("Roll No: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Total Marks: %d\n", students[i].totalMarks);
        printf("Percentage: %.2f%%\n", students[i].percentage);
    }

    return 0;
}