#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for student
struct Student
{
    int rollNumber;
    char name[50];
    int marks[3];
    int totalMarks;
    float percentage;
};

// Function declarations
void acceptStudents(struct Student students[], int n);
void displayStudents(struct Student students[], int n);

void insertionSort(struct Student students[], int n);
void selectionSort(struct Student students[], int n);
void shellSort(struct Student students[], int n);

int linearSearch(struct Student students[], int n, int key);
int binarySearch(struct Student students[], int n, int key);


// Main function
int main()
{
    struct Student students[MAX];
    int n, choice, key, result;

    printf("Enter number of students: ");
    scanf("%d", &n);

    acceptStudents(students, n);

    do
    {
        printf("\n========== STUDENT DATABASE ==========\n");
        printf("1. Display Students\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayStudents(students, n);
                break;

            case 2:
                insertionSort(students, n);
                printf("\nStudents sorted using Insertion Sort:\n");
                displayStudents(students, n);
                break;

            case 3:
                selectionSort(students, n);
                printf("\nStudents sorted using Selection Sort:\n");
                displayStudents(students, n);
                break;

            case 4:
                shellSort(students, n);
                printf("\nStudents sorted using Shell Sort:\n");
                displayStudents(students, n);
                break;

            case 5:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &key);

                result = linearSearch(students, n, key);

                if(result != -1)
                {
                    printf("\nStudent Found!\n");
                    printf("Roll Number: %d\n", students[result].rollNumber);
                    printf("Name: %s\n", students[result].name);
                    printf("Total Marks: %d\n", students[result].totalMarks);
                    printf("Percentage: %.2f%%\n",
                           students[result].percentage);
                }
                else
                {
                    printf("\nStudent not found.\n");
                }
                break;

            case 6:
                // Binary search requires sorted data
                insertionSort(students, n);

                printf("\nStudents sorted by Roll Number:\n");
                displayStudents(students, n);

                printf("\nEnter Roll Number to search: ");
                scanf("%d", &key);

                result = binarySearch(students, n, key);

                if(result != -1)
                {
                    printf("\nStudent Found!\n");
                    printf("Roll Number: %d\n", students[result].rollNumber);
                    printf("Name: %s\n", students[result].name);
                    printf("Total Marks: %d\n", students[result].totalMarks);
                    printf("Percentage: %.2f%%\n",
                           students[result].percentage);
                }
                else
                {
                    printf("\nStudent not found.\n");
                }
                break;

            case 7:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}


// Accept student details
void acceptStudents(struct Student students[], int n)
{
    int i, j, sum;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter marks in 3 subjects: ");

        sum = 0;

        for(j = 0; j < 3; j++)
        {
            scanf("%d", &students[i].marks[j]);
            sum = sum + students[i].marks[j];
        }

        students[i].totalMarks = sum;

        students[i].percentage =
            (sum / 300.0) * 100;
    }
}


// Display students
void displayStudents(struct Student students[], int n)
{
    int i;

    printf("\n--------------------------------------------------\n");
    printf("Roll No\tName\t\tTotal\tPercentage\n");
    printf("--------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%-15s\t%d\t%.2f%%\n",
               students[i].rollNumber,
               students[i].name,
               students[i].totalMarks,
               students[i].percentage);
    }

    printf("--------------------------------------------------\n");
}


// Insertion Sort
void insertionSort(struct Student students[], int n)
{
    int i, j;
    struct Student key;

    for(i = 1; i < n; i++)
    {
        key = students[i];
        j = i - 1;

        while(j >= 0 && students[j].rollNumber > key.rollNumber)
        {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }
}


// Selection Sort
void selectionSort(struct Student students[], int n)
{
    int i, j, min;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(students[j].rollNumber <
               students[min].rollNumber)
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = students[i];
            students[i] = students[min];
            students[min] = temp;
        }
    }
}


// Shell Sort
void shellSort(struct Student students[], int n)
{
    int gap, i, j;
    struct Student temp;

    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = students[i];

            for(j = i;
                j >= gap &&
                students[j - gap].rollNumber > temp.rollNumber;
                j = j - gap)
            {
                students[j] = students[j - gap];
            }

            students[j] = temp;
        }
    }
}


// Linear Search
int linearSearch(struct Student students[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(students[i].rollNumber == key)
        {
            return i;
        }
    }

    return -1;
}


// Binary Search
int binarySearch(struct Student students[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(students[mid].rollNumber == key)
        {
            return mid;
        }
        else if(key < students[mid].rollNumber)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}