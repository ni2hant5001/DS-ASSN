
#include <stdio.h>

void accept(int a[10][10], int r, int c);
void display(int a[10][10], int r, int c);
void addition(int a[10][10], int b[10][10], int r, int c);
void subtraction(int a[10][10], int b[10][10], int r, int c);
void multiplication(int a[10][10], int b[10][10], int r1, int c1, int c2);
void transpose(int a[10][10], int r, int c);

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;
    int choice;

    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d%d", &r1, &c1);

    if(r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10)
    {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    printf("Enter elements of Matrix 1:\n");
    accept(a, r1, c1);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d%d", &r2, &c2);

    if(r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10)
    {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    printf("Enter elements of Matrix 2:\n");
    accept(b, r2, c2);

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose of Matrix 1\n");
        printf("5. Display Matrices\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(r1 == r2 && c1 == c2)
                    addition(a, b, r1, c1);
                else
                    printf("Addition not possible.\n");
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                    subtraction(a, b, r1, c1);
                else
                    printf("Subtraction not possible.\n");
                break;

            case 3:
                if(c1 == r2)
                    multiplication(a, b, r1, c1, c2);
                else
                    printf("Multiplication not possible.\n");
                break;

            case 4:
                transpose(a, r1, c1);
                break;

            case 5:
                printf("\nMatrix 1:\n");
                display(a, r1, c1);

                printf("\nMatrix 2:\n");
                display(b, r2, c2);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void accept(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void addition(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sum[10][10];

    printf("\nAddition of matrices:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%4d", sum[i][j]);
        }
        printf("\n");
    }
}

void subtraction(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sub[10][10];

    printf("\nSubtraction of matrices:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
            printf("%4d", sub[i][j]);
        }
        printf("\n");
    }
}

void multiplication(int a[10][10], int b[10][10],
                    int r1, int c1, int c2)
{
    int i, j, k, mul[10][10];

    printf("\nMultiplication of matrices:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            mul[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }

            printf("%4d", mul[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[10][10], int r, int c)
{
    int i, j;

    printf("\nTranspose of Matrix 1:\n");

    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%4d", a[j][i]);
        }
        printf("\n");
    }
}
