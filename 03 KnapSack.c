#include<stdio.h>

void printintArray(int arr[], int n);
void printfloatArray(float arr[], int n);
void MergeSort(float PWratio[], int P[], int W[], int low, int high);
void Merge(float PWratio[], int P[], int W[], int low, int mid, int high);

int main()
{
    int n;
    printf("Enter number of items: ");
    scanf(" %d", &n);

    int P[n];
    printf("Enter the profits: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &P[i]);

    int W[n];
    printf("Enter the weights: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &W[i]);

    int M;
    printf("Enter the Knapsack capacity: ");
    scanf(" %d", &M);

    float PWratio[n];
    for(int i=0; i<n; i++)
        PWratio[i] = (float)P[i] / W[i];

    MergeSort(PWratio, P, W, 0, n-1);
    printf("\n\n");

    printf("Number of items: %d\n", n);

    printf("Knapsack capacity: %d\n", M);

    printf("Profits: ");
    printintArray(P, n);

    printf("Weights: ");
    printintArray(W, n);

    printf("Profit-Weight ratio: ");
    printfloatArray(PWratio, n);

    float X[n];
    for(int i=0; i<n; i++)
        X[i] = 0.0;

    float Profit=0.0, rem=M;
    int i;

    for(i=0; i<n; i++)
    {
        if(W[i] > rem)
            break;
        
        X[i] = 1.0;
        Profit += P[i];
        rem -= W[i];
    }
    if(i <= n)
    {
        X[i] = rem / W[i];
        rem -= X[i] * W[i];
        Profit += X[i] * P[i];
    }

    printf("Total Profit: %.2f\n", Profit);
    printf("Capacity filled: %.2f\n", M-rem);
    printf("Solution array: ");
    printfloatArray(X, n);

    return 0;
}

void printintArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void printfloatArray(float arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%.2f\t", arr[i]);
    printf("\n");
}

void MergeSort(float PWratio[], int P[], int W[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;

        MergeSort(PWratio, P, W, low, mid);
        MergeSort(PWratio, P, W, mid+1, high);

        Merge(PWratio, P, W, low, mid, high);
    }
}

void Merge(float PWratio[], int P[], int W[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=0, temp1[high+1], temp2[high+1];
    float temp3[high+1];

    while(i <= mid && j <= high)
    {
        if(PWratio[i] >= PWratio[j])
        {
            temp1[k] = P[i];
            temp2[k] = W[i];
            temp3[k++] = PWratio[i++];
        }
        else
        {
            temp1[k] = P[j];
            temp2[k] = W[j];
            temp3[k++] = PWratio[j++];
        }
    }
    while(i <= mid)
    {
        temp1[k] = P[i];
        temp2[k] = W[i];
        temp3[k++] = PWratio[i++];
    }
    while(j <= high)
    {
        temp1[k] = P[j];
        temp2[k] = W[j];
        temp3[k++] = PWratio[j++];
    }

    for(int i=low, k=0; i<=high; i++, k++)
    {
        P[i] = temp1[k];
        W[i] = temp2[k];
        PWratio[i] = temp3[k];
    }
}