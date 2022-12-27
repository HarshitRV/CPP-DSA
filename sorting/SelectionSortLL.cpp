#include <iostream>

using namespace std;

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

int main()
{
    int arr[] = {1, 34, 43, 32, 32, 4, 53, 10};
    selectionSort(arr, (sizeof(arr) / sizeof(int)));
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " - ";
    }
    return 0;
}