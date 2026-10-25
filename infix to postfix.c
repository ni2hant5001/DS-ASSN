#include <stdio.h>
#include <ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
    {
        printf("\nStack is full");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop()
{
    char temp;

    if (!isEmpty())
    {
        temp = stack[top];
        top = top - 1;
        return temp;
    }

    return '\0';
}

void push(char item)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = item;
    }
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }

    if (ch == '^')
    {
        return 3;
    }

    return 0;
}

int icp(char cp)
{
    if (cp == '+' || cp == '-')
    {
        return 1;
    }

    if (cp == '*' || cp == '/')
    {
        return 2;
    }

    if (cp == '^')
    {
        return 4;
    }

    return 0;
}

void in_post(char inexp[], char postexp[])
{
    int k = 0, i = 0;
    char tkn;

    tkn = inexp[i];

    while (tkn != '\0')
    {
        if (isalpha(tkn))
        {
            postexp[k] = tkn;
            k++;
        }
        else
        {
            if (tkn == '(')
            {
                push(tkn);
            }
            else
            {
                if (tkn == ')')
                {
                    while (!isEmpty() && stack[top] != '(')
                    {
                        postexp[k] = pop();
                        k++;
                    }

                    if (!isEmpty() && stack[top] == '(')
                    {
                        pop();
                    }
                }
                else
                {
                    while (!isEmpty() && 
                           isp(stack[top]) >= icp(tkn))
                    {
                        postexp[k] = pop();
                        k++;
                    }

                    push(tkn);
                }
            }
        }

        i++;
        tkn = inexp[i];
    }

    while (!isEmpty())
    {
        postexp[k] = pop();
        k++;
    }

    postexp[k] = '\0';

    printf("\nThe postfix expression is: %s\n", postexp);
}

int main()
{
    char infix[20];
    char postfix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    in_post(infix, postfix);

    return 0;
}