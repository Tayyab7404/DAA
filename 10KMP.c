#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* ComputeLPS(char *s, int n);

int main()
{
    char t[50];
    printf("Enter the string: ");
    scanf(" %[^\n]s", t);

    char pattern[10];
    printf("Enter the pattern to search: ");
    scanf(" %[^\n]s", pattern);

    int *res = ComputeLPS(pattern, strlen(pattern));

    int pos[strlen(t)], idx=0, i=0, j=0;

    while( i < strlen(t))
    {
        if (t[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = res[j-1];
            else
                i++;
        }
        if (j == strlen(pattern))
        {
            pos[idx++] = (i - strlen(pattern));
            j = 0;
        }
    }

    printf("Positions where pattern is found: ");
    for (int i=0; i<idx; i++)
        printf("%d ", pos[i]);
    printf("\n");
}

int* ComputeLPS(char *s, int n)
{
    int *lps = (int*)malloc(n * sizeof(int));
    lps[0] = 0;

    for (int i = 1; i < n; i++)
        lps[i] = 0;

    for (int i = 1; i < n; i++)
    {
        int j = lps[i-1];

        while (j > 0 && s[i] != s[j])
            j = lps[j-1];

        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }   
    return lps;
}