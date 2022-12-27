#include <iostream>

using namespace std;

void insertionSort(int arr[], int len)
{
    int j;
    for (int i = 1; i < len; i++)
    {
        j = i - 1;
        int x = arr[i];

        while (j > -1 && x < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = {5, 7, 3, 5, 2, 8, 9, 10, 12, 6};

    insertionSort(arr, sizeof(arr)/sizeof(int));

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " - ";
    }
    return 0;
}