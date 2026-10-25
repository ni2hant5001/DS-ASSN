
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

typedef struct Node Node;

// Create a new node
Node *createNode(int coeff, int exp)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;

    return newNode;
}

// Insert a term in descending order
void insertTerm(Node **head, int coeff, int exp)
{
    Node *temp, *prev, *newNode, *last;

    if (coeff == 0)
        return;

    if (*head == NULL)
    {
        *head = createNode(coeff, exp);
        return;
    }

    temp = *head;
    prev = NULL;

    do
    {
        if (temp->exp == exp)
        {
            temp->coeff += coeff;

            if (temp->coeff == 0)
            {
                if (temp->next == temp)
                {
                    free(temp);
                    *head = NULL;
                    return;
                }

                if (temp == *head)
                {
                    last = *head;

                    while (last->next != *head)
                        last = last->next;

                    *head = temp->next;
                    last->next = *head;
                }
                else
                {
                    prev->next = temp->next;
                }

                free(temp);
            }

            return;
        }

        if (temp->exp < exp)
            break;

        prev = temp;
        temp = temp->next;

    } while (temp != *head);

    newNode = createNode(coeff, exp);

    if (temp == *head && exp > (*head)->exp)
    {
        last = *head;

        while (last->next != *head)
            last = last->next;

        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = temp;
    }
}

// Create a polynomial
Node *createPolynomial()
{
    Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of terms\n");
        return NULL;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        if (exp < 0)
        {
            printf("Exponent must be non-negative\n");
            i--;
            continue;
        }

        insertTerm(&head, coeff, exp);
    }

    return head;
}

// Display a polynomial
void displayPolynomial(Node *head)
{
    Node *temp;
    int first = 1, c, e;

    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    temp = head;

    do
    {
        c = temp->coeff;
        e = temp->exp;

        if (c != 0)
        {
            if (!first)
                printf(c > 0 ? " + " : " - ");
            else if (c < 0)
                printf("-");

            if (e == 0)
                printf("%d", abs(c));
            else
            {
                if (abs(c) != 1)
                    printf("%d", abs(c));

                printf("x");

                if (e != 1)
                    printf("^%d", e);
            }

            first = 0;
        }

        temp = temp->next;

    } while (temp != head);

    if (first)
        printf("0");

    printf("\n");
}

// Add two polynomials
Node *addPolynomial(Node *p1, Node *p2)
{
    Node *result = NULL;
    Node *temp;

    if (p1 != NULL)
    {
        temp = p1;

        do
        {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p1);
    }

    if (p2 != NULL)
    {
        temp = p2;

        do
        {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p2);
    }

    return result;
}

// Free all nodes
void freePolynomial(Node **head)
{
    Node *temp, *current;

    if (*head == NULL)
        return;

    current = (*head)->next;

    while (current != *head)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(*head);
    *head = NULL;
}

int main()
{
    Node *p1, *p2, *sum;

    printf("Create first polynomial:\n");
    p1 = createPolynomial();

    printf("\nCreate second polynomial:\n");
    p2 = createPolynomial();

    printf("\nFirst polynomial: ");
    displayPolynomial(p1);

    printf("Second polynomial: ");
    displayPolynomial(p2);

    sum = addPolynomial(p1, p2);

    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    freePolynomial(&p1);
    freePolynomial(&p2);
    freePolynomial(&sum);

    printf("Memory deallocated successfully\n");

    return 0;
}
