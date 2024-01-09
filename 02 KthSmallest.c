#include<stdio.h>

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

    int k;
    printf("Enter the value of K: ");
    scanf(" %d", &k);

    MergeSort(arr, 0, n-1);

    printf("The %dth smallest element in the array is : %d\n", k, arr[k-1]);

    return 0;
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