#include <iostream>

using namespace std;

void countSort(int arr[], int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int *countArr = new int[max + 1];

    for (int i = 0; i < len; i++)
    {
        countArr[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (countArr[i] > 0)
        {
            while (countArr[i] > 0)
            {
                arr[j++] = i;
                countArr[i]--;
            }
        }
    }
}

int main()
{
    int arr[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};

    countSort(arr, 10);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " - ";
    return 0;
}