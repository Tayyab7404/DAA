#include <stdio.h>

void MergeSort(int a[], int l, int h);
void Merge(int a[], int low, int mid, int high);
void printArray(int arr[], int n);

int main() 
{
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("Elements before sorting: ");
  printArray(arr, n);

  MergeSort(arr, 0, n - 1);

  printf("Elements after sorting: ");
  printArray(arr, n);
}

void printArray(int arr[], int n) 
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void MergeSort(int a[], int l, int h) 
{
  if (l < h) 
  {
    int m = (l + h) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, h);
    Merge(a, l, m, h);
  }
}

void Merge(int a[], int low, int mid, int high) 
{
  int i = low, j = mid + 1, k = 0, temp[high + 1];

  while (i <= mid && j <= high) 
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

  for (i = low, k = 0; i <= high; i++, k++)
    a[i] = temp[k];
}