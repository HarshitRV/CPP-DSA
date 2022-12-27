#include <iostream>

using namespace std;

void insertionSort(int arr[], int len)
{
    int j;
    for (int i = 1; i < len; i++)
    {
        j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void selectionSort(int arr[], int len)
{
    int j, k;
    for (int i = 0; i < len; i++)
    {
        j = k = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}