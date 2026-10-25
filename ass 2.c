#include <stdio.h>

int main()
{
    int a[10][10], s[3][101], t[3][101];
    int m, n, i, j, k = 1;

    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &m, &n);

    if (m > 10 || n > 10 || m <= 0 || n <= 0) {
        printf("Error: Matrix dimensions must be between 1 and 10.\n");
        return 1;
    }

    printf("Enter row and columns value of the matrix: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)  // sparse matrix formation 
            {
                s[0][k] = i;
                s[1][k] = j;
                s[2][k] = a[i][j];
                k++;
            }
        }
    }

    s[0][0] = m;
    s[1][0] = n;
    s[2][0] = k - 1;

    printf("Sparse matrix is: \n");
    for (i = 0; i < k; i++)
    {
        printf("%d %d %d\n", s[0][i], s[1][i], s[2][i]);
    }


    t[0][0] = s[1][0]; 
    t[1][0] = s[0][0];
    t[2][0] = s[2][0];
    int num_cols = s[1][0];
    int num_terms = s[2][0];

    if (num_terms > 0)
    {
        int count[100] = {0};
        int start_pos[100] = {0};

        for (i = 1; i <= num_terms; i++)
        {
            count[s[1][i]]++;
        }


        start_pos[0] = 1;
        for (i = 1; i < num_cols; i++)
        {
            start_pos[i] = start_pos[i - 1] + count[i - 1];
        }


        for (i = 1; i <= num_terms; i++)
        {
            int col = s[1][i];
            int pos = start_pos[col];

            t[0][pos] = s[1][i];
            t[1][pos] = s[0][i];
            t[2][pos] = s[2][i];
            start_pos[col]++;
        }
    }

    printf("Transposed Sparse matrix (Fast Transpose) is: \n");
    for (i = 0; i <= num_terms; i++)
    {
        printf("%d %d %d\n", t[0][i], t[1][i], t[2][i]);
    }

    return 0;
}
