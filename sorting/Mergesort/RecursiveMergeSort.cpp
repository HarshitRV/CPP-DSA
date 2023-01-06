#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    cout << "called merge" << endl;
    int i = low;
    int j = mid + 1;
    int k = low;
    int *arr2 = new int[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    for (; i <= mid; i++)
    {
        arr2[k++] = arr[i];
    }
    for (; j <= high; j++)
    {
        arr2[k++] = arr[j];
    }

    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << endl;
        arr[i] = arr2[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high-low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    //               mid|
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
    mergeSort(A, 0, n-1);
    // mergeSort(A, 0, 7);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " - ";
    }
    return 0;
}