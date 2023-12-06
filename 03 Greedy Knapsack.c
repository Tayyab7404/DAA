#include <stdio.h>

void Merge(float r[], int p[], int w[], int l, int m, int h);
void MergeSort(float r[],int p[], int w[], int l, int h);
void Greedy(float r[], int p[], int w[], int m, int n);

int main()
{
    int n, m;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);

    int p[n], w[n];
    float r[n];

    printf("Enter profits and weights of each item: \n");
    for (int i=0; i<n; i++)
    {
        printf("\tItem %d: ", i+1);
        scanf("%d %d", &p[i], &w[i]);
        r[i] = (float)p[i]/w[i];
    }

    MergeSort(r, p, w, 0, n-1);

    Greedy(r, p, w, m, n);

    return 0;
}

void MergeSort(float r[],int p[], int w[], int l, int h)
{
    if (l<h)
    {
        int m = (l+h) / 2;

        MergeSort(r, p, w, l, m);
        MergeSort(r, p, w, m+1, h);

        Merge(r, p, w, l, m, h);
    }
}

void Merge(float r[], int p[], int w[], int l, int m, int h)
{
    int i = l;
    int j = m+1;
    int k = 0;

    float temp1[h+1];
    int temp2[h+1], temp3[h+1];

    while (i<=m && j<=h)
    {
        if (r[i] >= r[j])
        {
            temp1[k] = r[i];
            temp2[k] = p[i];
            temp3[k++] = w[i++];
        }
        else
        {
            temp1[k] = r[j];
            temp2[k] = p[j];
            temp3[k++] = w[j++];
        }
    }
    while (i <= m)
    {
        temp1[k] = r[i];
        temp2[k] = p[i];
        temp3[k++] = w[i++];
    }
    while (j <= h)
    {
        temp1[k] = r[j];
        temp2[k] = p[j];
        temp3[k++] = w[j++];
    }

    for (int i=l, k=0; i<=h; i++, k++)
    {
        r[i] = temp1[k];
        p[i] = temp2[k];
        w[i] = temp3[k];
    }
}

void Greedy(float r[], int p[], int w[], int m, int n)
{
    float x[n];
    for (int i=0; i<n; i++)
        x[i] = 0.0;

    float tProfit = 0.0;
    int curr = m, i;

    for (i=0; i<n; i++)
    {
        if (w[i] > curr)  break;
        x[i] = 1.0;
        curr = curr - w[i];
        tProfit += p[i];
    }

    if (i <= n)
    {
        x[i] = (float)curr / w[i];
        curr -= x[i] * w[i];
        tProfit += p[i] * x[i];
    }

    printf("Total profit= %.2f \nCapacity filled = %d\n", tProfit, m-curr);

    printf("Selected items are: \n");
    for (int i=0; i<n; i++)
    {
        if (x[i] == 0.0) continue;
        printf("Item %d: Fraction = %.2f, Profit = %d, Weight = %d\n", i, x[i], p[i], w[i]);
    }
}
