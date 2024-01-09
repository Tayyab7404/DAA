#include<stdio.h>
#include<stdlib.h>

void NQueens(int* X, int k, int n);
int place(int* X, int k, int i);

int main()
{
    int n;
    printf("Enter number of Queens: ");
    scanf(" %d", &n);

    int* X = (int*)malloc((n+1) * sizeof(n));

    NQueens(X, 1, n);
}

void NQueens(int* X, int k, int n)
{
    for(int i=1; i<=n; i++)
    {
        if(place(X, k, i))
        {
            X[k] = i;

            if(k == n)
            {
                for(int j=1; j<=n; j++)
                    printf("%d ", X[j]);
                printf("\n");
            }
            else
                NQueens(X, k+1, n);
        }
    }
}

int place(int* X, int k, int i)
{
    for(int j=1; j<k; j++)
        if(X[j] == i || abs(j - k) == abs(X[j] - i))
            return 0;
    return 1;
}