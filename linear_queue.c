#include <stdio.h>
#include <string.h>

#define MAX 5

struct PrintJob
{
    int jobID;
    char title[50];
};

struct PrintJob queue[MAX];

int front = -1;
int rear = -1;

// Enqueue
void enqueue()
{
    struct PrintJob job;

    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow! Print queue is full.\n");
        return;
    }

    printf("\nEnter Job ID: ");
    scanf("%d", &job.jobID);

    printf("Enter Document Title: ");
    scanf("%s", job.title);

    if (front == -1)
        front = 0;

    rear++;

    queue[rear] = job;

    printf("Print job added successfully.\n");
}

// Dequeue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! No print jobs available.\n");
        return;
    }

    printf("\nProcessed Print Job:");
    printf("\nJob ID: %d", queue[front].jobID);
    printf("\nDocument Title: %s\n", queue[front].title);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Display
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nNo Pending Print Jobs.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");

    for (i = front; i <= rear; i++)
    {
        printf("\nJob ID: %d", queue[i].jobID);
        printf("\nDocument Title: %s\n", queue[i].title);
    }
}

// Main
int main()
{
    int choice;

    printf("===== PRINTER QUEUE MANAGER - LINEAR QUEUE =====\n");

    while (1)
    {
        printf("\n\n1. Enqueue Print Job");
        printf("\n2. Dequeue Print Job");
        printf("\n3. Display Print Jobs");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram terminated successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}