#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* ComputeLPS(char S[], int n);

int main()
{
    char S[50];
    printf("Enter the string: ");
    scanf(" %[^\n]s", S);

    char pattern[10];
    printf("Enter the pattern: ");
    scanf(" %[^\n]s", pattern);

    int* LPS = ComputeLPS(pattern, strlen(pattern));

    int pos[strlen(S)], idx=0, i=0, j=0;

    while(i < strlen(S))
    {
        if(S[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0) 
                j = LPS[j-1];
            else
                i++;
        }

        if(j == strlen(pattern))
        {
            pos[idx++] = i - strlen(pattern);
            j = 0;
        }
    }

    printf("Positions where pattern is found: ");
    for(int i=0; i<idx; i++)
        printf("%d ", pos[i]);
    printf("\n");

    return 0;
}

int* ComputeLPS(char S[], int n)
{
    int* LPS = (int*)malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
        LPS[i] = 0;

    for(int i=1; i<n; i++)
    {
        int j = LPS[i-1];

        while(j>0 && S[i]!=S[j])
            j = LPS[j-1];

        if(S[i] == S[j]) 
            j++;

        LPS[i] = j;
    }

    return LPS;
}