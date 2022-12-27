#include <iostream>

using namespace std;

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int j, k;
        j = k = i;
        for (int j = i + 1; j < len; j++)
        {
            // Bring k to j is j is pointing to a smaller element
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        // Swap element at index i with k
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main()
{
    int arr[] = {2, 1, 242, 21, 43, 532, 123, 12, 3};
    int len = sizeof(arr) / sizeof(int);

    selectionSort(arr, len);
    for (int i = 0; i < len; i++)
    {  
        cout<<arr[i]<<" -->";
    }

    return 0;
}