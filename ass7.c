#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int calculate(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        case '%':
            return a % b;

        case '^':
        {
            int result = 1;

            for (int i = 0; i < b; i++)
                result *= a;

            return result;
        }

        default:
            return 0;
    }
}

int evaluatePostfix(char exp[])
{
    int i;
    char ch;
    int a, b;

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            b = pop();
            a = pop();

            push(calculate(a, b, ch));
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}