#include<stdio.h>

void printArray(int arr[], int n);
void MergeSort(int arr[], int low, int high);
void Merge(int arr[], int low, int mid, int high);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf(" %d", &n);

    int arr[n];
    printf("Enter elements into the array: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &arr[i]);

    printf("Elements before sorting: ");
    printArray(arr, n);

    MergeSort(arr, 0, n-1);

    printf("Elements after sorting: ");
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void MergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);

        Merge(arr, low, mid, high);
    }
}

void Merge(int arr[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=0, temp[high+1];

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];

    for(int i=low, k=0; i<=high; i++, k++)
        arr[i] = temp[k];
}