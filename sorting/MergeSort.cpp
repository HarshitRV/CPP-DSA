#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a single sorted array
void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    // Iterate through both arrays and add the smaller element to the result array
    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Add the remaining elements from the left array, if any
    while (i < left_size)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Add the remaining elements from the right array, if any
    while (j < right_size)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Recursive function to sort an array using merge sort
void merge_sort(int arr[], int size)
{
    // Base case: if the array has 1 element or less, it is already sorted
    if (size <= 1)
        return;

    // Divide the array into two halves
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    // Sort the left and right halves
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted left and right halves
    merge(arr, left, mid, right, size - mid);
}

int main()
{
    int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
