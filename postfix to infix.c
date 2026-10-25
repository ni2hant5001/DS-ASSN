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

void post_in(char postfix[], char infix[])
{
    int i;
    char op1[MAX], op2[MAX], temp[MAX];

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalpha(postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';

            push(temp);
        }
        else
        {
            pop(op2);
            pop(op1);

            temp[0] = '\0';

            strcat(temp, "(");
            strcat(temp, op1);

            int len = strlen(temp);
            temp[len] = postfix[i];
            temp[len + 1] = '\0';

            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
    }

    pop(infix);

    printf("\nThe infix expression is: %s\n", infix);
}

int main()
{
    char postfix[MAX];
    char infix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    post_in(postfix, infix);

    return 0;
}