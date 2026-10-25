#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char stack[MAX][MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
    {
        printf("\nStack is full");
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char item[])
{
    if (!isFull())
    {
        top++;
        strcpy(stack[top], item);
    }
}

void pop(char item[])
{
    if (!isEmpty())
    {
        strcpy(item, stack[top]);
        top--;
    }
}

void pre_post(char prefix[], char postfix[])
{
    int i;
    char op1[MAX], op2[MAX], temp[MAX];

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (isalpha(prefix[i]))
        {
            temp[0] = prefix[i];
            temp[1] = '\0';

            push(temp);
        }
        else
        {
            pop(op1);
            pop(op2);

            strcpy(temp, op1);
            strcat(temp, op2);

            int len = strlen(temp);
            temp[len] = prefix[i];
            temp[len + 1] = '\0';

            push(temp);
        }
    }

    pop(postfix);

    printf("\nThe postfix expression is: %s\n", postfix);
}

int main()
{
    char prefix[MAX];
    char postfix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    pre_post(prefix, postfix);

    return 0;
}