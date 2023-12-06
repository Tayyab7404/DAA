#include <stdio.h>

void MergeSort(int a[], int l, int h);
void Merge(int a[], int low, int mid, int high);

int main() 
{
    int n, k;
  
    printf("Enter the size of the array: ");
    scanf("%d", &n);
  
    int arr[n];
  
    printf("Enter the elements: ");
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
  
    MergeSort(arr, 0, n-1);
  
    printf("Enter the value of k: ");
    scanf("%d", &k);
  
    printf("%dth smallest element is %d\n", k, arr[k-1]);
}

void MergeSort(int a[], int l, int h) 
{
    if (l<h) 
    {
        int m = (l+h) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, h);
        Merge(a, l, m, h);
    }
}

void Merge(int a[], int low, int mid, int high) 
{
    int i=low, j=mid+1, k=0, temp[high+1];

    while (i<=mid && j<=high) 
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j < high)
        temp[k++] = a[j++];

    for (i=low, k=0; i<=high; i++, k++)
        a[i] = temp[k];
}
