#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int regNo;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

/* Add a student at the end */
void addStudent() {
    struct Student *newNode, *temp;
    int regNo;

    newNode = (struct Student *)malloc(sizeof(struct Student));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &regNo);

    temp = head;
    while (temp != NULL) {
        if (temp->regNo == regNo) {
            printf("Registration number already exists.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->regNo = regNo;

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

/* Remove a student using registration number */
void removeStudent() {
    struct Student *temp = head;
    struct Student *prev = NULL;
    int regNo;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &regNo);

    while (temp != NULL && temp->regNo != regNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student record deleted successfully.\n");
}

/* Display all students */
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("\nRegistration No.\tStudent Name\n");
    printf("--------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t\t\t%s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
}

/* Count total participants */
void countStudents() {
    struct Student *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", count);
}

/* Sort students by registration number */
void sortStudents() {
    struct Student *i, *j;
    int tempReg;
    char tempName[50];

    if (head == NULL || head->next == NULL) {
        printf("List is already sorted.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                tempReg = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempReg;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Students sorted by Registration Number.\n");
}

/* Reverse the linked list */
void reverseList() {
    struct Student *prev = NULL;
    struct Student *current = head;
    struct Student *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    printf("List reversed successfully.\n");
}

/* Release all allocated memory */
void freeList() {
    struct Student *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("All student records deleted.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== WORKSHOP ENROLLMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Count Participants\n");
        printf("5. Sort Students\n");
        printf("6. Reverse List\n");
        printf("7. Delete All Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                countStudents();
                break;

            case 5:
                sortStudents();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                freeList();
                break;

            case 0:
                freeList();
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
    return 0;
}
