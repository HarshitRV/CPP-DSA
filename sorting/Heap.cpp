#include <iostream>

using namespace std;

/**
 * @brief swap array elements
 *
 * @param a int pointer
 * @param b int pointer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    a = b;
    *b = temp;
}

/**
 * @brief create max heap
 *
 * @param arr array of intergers
 * @param n size of the array
 */
void insertHeap(int arr[], int n)
{
    int temp = arr[n];
    int i = n;

    while (i > 0 && temp > arr[i / 2])
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = temp;
}

/**
 * @brief heap sort
 *
 * @param arr array of integers
 * @param lastIndex int
 * @return int
 */
int maxHeapSort(int arr[], int lastIndex)
{
    int deletedItem = arr[0];
    arr[0] = arr[lastIndex];
    int i = 0;
    int j = (2 * i) + 1;

    while (j < lastIndex)
    {
        // compare right child with left child
        if (arr[j + 1] > arr[j])
        {
            // right child greater bring j to right child
            j = j + 1;
        }
        // compare new root item with the greater child(left or right)
        if (arr[i] < arr[j])
        {
            // if root is smaller swap root with child
            swap(arr[i], arr[j]);
            // move i to the j where we swapped
            i = j;
            // move j to next child element of the new i position.
            j = (2 * i) + 1;
        }
        else
        {
            break;
        }
    }
    arr[lastIndex] = deletedItem;
    return deletedItem;
}

int main()
{
    // int arr[] = {30, 20, 15, 5, 10, 12, 6, 40};

    // insertHeap(arr, 7);
    // cout << "\n";
    // for (int i = 0; i < (sizeof(arr) / sizeof(arr[i])); i++)
    // {

    //     cout << arr[i] << " - ";
    // }
    int arr2[] = {10, 20, 30, 25, 5, 40, 35};
    for (int i = 1; i < (sizeof(arr2) / sizeof(arr2[i])); i++)
    {
        insertHeap(arr2, i);
    }
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[i])); i++)
    {

        cout << arr2[i] << " - ";
    }

    maxHeapSort(arr2, 6);
    maxHeapSort(arr2, 5);
    maxHeapSort(arr2, 4);
    maxHeapSort(arr2, 3);
    maxHeapSort(arr2, 2);
    maxHeapSort(arr2, 1);

    cout << endl;
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[i])); i++)
    {

        cout << arr2[i] << " - ";
    }
    return 0;
}